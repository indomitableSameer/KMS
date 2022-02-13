#include <KmsLogic.h>
#include <DataReceiver.h>
#include <DBAccessProvider.h>
#include <AlarmLogic.h>
#include <AlarmSoundManager.h>
#include <AlarmPredictionLogic.h>
#include <QtDebug>

KMSLogic::KMSLogic()
{
    initialize();
}

void KMSLogic::initialize()
{
    m_dataReceiver = new DataReceiver("E:\\QtLearning\\KMS_T\\resources\\test_data\\testdata.csv");
    m_db_reader = new DBAccessProvider();
    m_db_writer = new DBAccessProvider();
    m_alarmManager = new AlarmManager();
    m_predictionLogic = new AlarmPredictionLogic();
    m_notificationGenerator = new NotificationGenerator();
    dataReceiverFailCounter = 0;
    DataReceiver::connect(m_dataReceiver, &IDataReceiver::dataAvailable, this, &KMSLogic::processDataReceiver);
}

/*
 * Hazard Id : _H1.4_error_on_failed_payload_
 *             _H4.2_timestamp_
*/
void KMSLogic::processor()
{
    try {
        int so2ppm = m_dataReceiver->getFromQueue();
        if(so2ppm == -1)
        {
            if(dataReceiverFailCounter < 3)
            {
                dataReceiverFailCounter++;
                return;
            }
            else
            {
                IUiData aUiData;
                QDateTime local(QDateTime::currentDateTime());
                aUiData.setDate(local);
                aUiData.setNotification("SYSTEM ERROR !! Unable to receiver sensor values.");
                emit processedDataAvailable(aUiData);
            }
        }

        QString aNotification = "";
        IAlarmType aAlarmRaised = m_alarmManager->HandlerAlarm(so2ppm);
        int aBlockageProbablity = m_predictionLogic->calculateBlockageProbablity(so2ppm);
        m_db_writer->WriteSo2LevelToDB(so2ppm);

        if(aAlarmRaised != IAlarmType::NONE)
        {
            aNotification = m_notificationGenerator->generateAlarmNotification(aAlarmRaised, so2ppm, aBlockageProbablity);
            m_db_writer->WriteAlarmDataToDB(static_cast<int>(aAlarmRaised));
            m_db_writer->WriteNotificationDataToDB(aNotification);

            qDebug() << aNotification;
            qDebug() << "Alarm Raised " << (aAlarmRaised==IAlarmType::RED? "RED" : "YELLOW") << "Probabity of Blockage: " << aBlockageProbablity;
        }

        IUiData aUiData;
        QDateTime local(QDateTime::currentDateTime());
        aUiData.setDate(local);
        aUiData.setSo2Ppm(so2ppm);
        aUiData.setNotification(aNotification);
        aUiData.setAlarmType(aAlarmRaised);

        emit processedDataAvailable(aUiData);
    }
    catch (exception& exp) {

        IUiData aUiData;
        QDateTime local(QDateTime::currentDateTime());
        aUiData.setDate(local);
        aUiData.setNotification(exp.what());
        emit processedDataAvailable(aUiData);
    }
}

bool KMSLogic::startProcessing()
{
    m_dataReceiver->start();
    return true;
}

IUiData KMSLogic::cancelAlarm()
{
    QDateTime local(QDateTime::currentDateTime());

    IUiData aUiData;

    if(m_alarmManager->cancelAlarm())
    {
        aUiData.setNotification(m_notificationGenerator->generateCancelNotification());
    }

    return aUiData;
}

void KMSLogic::processDataReceiver()
{
    processor();
}
