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
    DataReceiver::connect(m_dataReceiver, &IDataReceiver::dataAvailable, this, &KMSLogic::processDataReceiver);
}

void KMSLogic::processor()
{
    // TODO - put this into thread and use wait conditions to wakeup thread to process data
    raw_data data = UnprocessedDataQueue.dequeue();

    QString aNotification = "";
    IAlarmType aAlarmRaised = m_alarmManager->HandlerAlarm(data.so2PpmValue);
    int aBlockageProbablity = m_predictionLogic->calculateBlockageProbablity(data.so2PpmValue);
    m_db_writer->WriteSo2LevelToDB(data.so2PpmValue);

    if(aAlarmRaised != IAlarmType::NONE)
    {
         aNotification = m_notificationGenerator->generateAlarmNotification(aAlarmRaised, aBlockageProbablity);
         m_db_writer->WriteAlarmDataToDB(static_cast<int>(aAlarmRaised));
         m_db_writer->WriteNotificationDataToDB(aNotification);

         qDebug() << aNotification;
         qDebug() << "Alarm Raised " << (aAlarmRaised==IAlarmType::RED? "RED" : "YELLOW") << "Probabity of Blockage: " << aBlockageProbablity;
    }

    IUiData aUiData;
    aUiData.setDate(data.dateTime);
    aUiData.setSo2Ppm(data.so2PpmValue);
    aUiData.setNotification(aNotification);
    aUiData.setAlarmType(aAlarmRaised);

    emit processedDataAvailable(aUiData);
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
    aUiData.setNotification(m_notificationGenerator->generateCancelNotification());
    m_alarmManager->cancelAlarm();

    return aUiData;
}

void KMSLogic::processDataReceiver(int so2ppm)
{
    QDateTime local(QDateTime::currentDateTime());

    raw_data data;
    data.dateTime = local;
    data.so2PpmValue = so2ppm;

    //UnprocessedDataQueue.enqueue(data);
    QString aNotification;
    qDebug() << "Local date is:" << local.date().toString()<< "Local time is:" << local.time().toString() << " SO2 ppm :" << so2ppm ;

    IAlarmType aAlarmRaised = m_alarmManager->HandlerAlarm(so2ppm);
    int aBlockageProbablity = m_predictionLogic->calculateBlockageProbablity(so2ppm);
    m_db_writer->WriteSo2LevelToDB(so2ppm);

    if(aAlarmRaised != IAlarmType::NONE)
    {
         aNotification = m_notificationGenerator->generateAlarmNotification(aAlarmRaised, aBlockageProbablity);
         m_db_writer->WriteAlarmDataToDB(static_cast<int>(aAlarmRaised));
         m_db_writer->WriteNotificationDataToDB(aNotification);

         qDebug() << aNotification;
         qDebug() << "Alarm Raised " << (aAlarmRaised==IAlarmType::RED? "RED" : "YELLOW") << "Probabity of Blockage: " << aBlockageProbablity;
    }

    IUiData aUiData;
    aUiData.setDate(data.dateTime);
    aUiData.setSo2Ppm(data.so2PpmValue);
    aUiData.setNotification(aNotification);
    aUiData.setAlarmType(aAlarmRaised);

    emit processedDataAvailable(aUiData);
}
