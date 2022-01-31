#include "kmslogic.h"
#include "datareceiver.h"
#include "DBAccessProvider.h"
#include "alarmlogic.h"
#include "alarmsound.h"
#include "alarmpredictionlogic.h"
#include "kmsresponse.h"
#include <queue>
#include <QtDebug>

double ppmLevel = 600;
queue<KmsResponse> dataQueue;

KMSLogic::KMSLogic()
{
    initialize();
}

void KMSLogic::kmsLogicFunction(double ppmLevel)
{
    AlarmLogic alarmCommandObject;
    AlarmPredictionLogic alarmPredictionObject;
    AlarmSound alarmSoundObject;
    KmsResponse responseData;

     int commandValue = alarmCommandObject.alarmCommand(ppmLevel);
     string commandPrediction = alarmPredictionObject.alarmPrediction(ppmLevel);

     alarmSoundObject.alarmSound(commandValue,true);

     responseData.setAlarmCommand(commandValue);
     responseData.setAlarmPrediction(commandPrediction);
     dataQueue.push(KmsResponse(responseData));
     emit kmssignal();
}

void KMSLogic::KmsDataReceiverFunction()
{
    //DataReceiver dataReceiver("Path to CSV");
    KMSLogic kmsLogic;
    //KMSLogic::connect(&dataReceiver,&DataReceiver::dataAvailable,&kmsLogic,&KMSLogic::kmsLogicFunction);
}

bool KMSLogic::startProcessing()
{
    m_dataReceiver->start();
    return true;
}

void KMSLogic::initialize()
{
    m_dataReceiver = new DataReceiver("E:\\QtLearning\\build-KMS_T-Desktop_Qt_5_15_1_MinGW_32_bit-Debug\\UserInterface\\debug\\testdata.csv");
    m_db_reader = new DBAccessProvider();
    m_db_writer = new DBAccessProvider();
    DataReceiver::connect(m_dataReceiver, &IDataReceiver::dataAvailable, this, &KMSLogic::processDataReceiver);
}

KmsResponse KMSLogic::kmsQueueData()
{
    //KmsResponse latestQueueData;
   return dataQueue.front();

}

void KMSLogic::processDataReceiver(int so2ppm)
{
    QDateTime local(QDateTime::currentDateTime());
    qDebug() << "Local date is:" << local.date().toString();
    qDebug() << "Local time is:" << local.time().toString();
    QDate d; QTime t;
    qDebug() << "test date is:" << d.isValid();
    qDebug() << "test time is:" << t.isValid();
    qDebug() << so2ppm << " -> data received\n";
}
