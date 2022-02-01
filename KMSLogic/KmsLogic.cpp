#include "KmsLogic.h"
#include "DataReceiver.h"
#include "DBAccessProvider.h"
#include <AlarmLogic.h>
#include "AlarmSoundManager.h"
#include "AlarmPredictionLogic.h"
#include "kmsresponse.h"
#include <queue>
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

bool KMSLogic::startProcessing()
{
    m_dataReceiver->start();
    return true;
}

void KMSLogic::processDataReceiver(int so2ppm)
{
    QDateTime local(QDateTime::currentDateTime());
    qDebug() << "Local date is:" << local.date().toString()<< "Local time is:" << local.time().toString() << " SO2 ppm :" << so2ppm ;

    IAlarmType aAlarmRaised = m_alarmManager->HandlerAlarm(so2ppm);
    int aBlockageProbablity = m_predictionLogic->calculateBlockageProbablity(so2ppm);
    m_db_writer->WriteSo2LevelToDB(so2ppm);

    if(aAlarmRaised != IAlarmType::NONE)
    {
         QString aNotification = m_notificationGenerator->generateAlarmNotification(aAlarmRaised, aBlockageProbablity);
         m_db_writer->WriteAlarmDataToDB(static_cast<int>(aAlarmRaised));
         m_db_writer->WriteNotificationDataToDB(aNotification);

         qDebug() << aNotification;
         qDebug() << "Alarm Raised " << (aAlarmRaised==IAlarmType::RED? "RED" : "YELLOW") << "Probabity of Blockage: " << aBlockageProbablity;
    }
}
