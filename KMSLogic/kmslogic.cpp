#include "kmslogic.h"
#include "datareceiver.h"
#include "DBAccessProvider.h"
#include "alarmlogic.h"
#include "alarmsound.h"
#include "alarmpredictionlogic.h"
#include "kmsresponse.h"
#include <queue>

double ppmLevel = 600;
queue<KmsResponse> dataQueue;


KMSLogic::KMSLogic(QObject *parent)
    : QObject{parent}
{

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
    DataReceiver dataReceiver("Path to CSV");
    KMSLogic kmsLogic;
    KMSLogic::connect(&dataReceiver,&DataReceiver::dataAvailable,&kmsLogic,&KMSLogic::kmsLogicFunction);
}

KmsResponse KMSLogic::kmsQueueData()
{
    //KmsResponse latestQueueData;
   return dataQueue.front();

}
