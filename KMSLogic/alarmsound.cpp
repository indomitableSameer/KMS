#include "alarmsound.h"
#include <QSound>
#include <iostream>
#include <string>
//#include <qdebug.h>

using namespace std;


int RED_ALARM_CODE = 2;
int YELLOW_ALARM_CODE = 1;

QString RED_ALARM_AUDIO_PATH = "C:/Users/anish/OneDrive/Documents/TestAudio2/alarm_red.wav";
QString YELLOW_ALARM_AUDIO_PATH = "C:/Users/anish/OneDrive/Documents/TestAudio2/alarm_red.wav";

QSound *playRedAudio = new QSound(RED_ALARM_AUDIO_PATH);
QSound *playYellowAudio = new QSound(YELLOW_ALARM_AUDIO_PATH);

AlarmSound::AlarmSound()
{

}

void AlarmSound::alarmSound(int alarmCode, bool alarmPlayPause)
{
    if(alarmPlayPause){
        if(alarmCode == RED_ALARM_CODE){
            playRedAlarm();
        }
        if(alarmCode == YELLOW_ALARM_CODE){
            playYellowAlarm();
        }
    }

    if(!alarmPlayPause){
        if(alarmCode == RED_ALARM_CODE){
            //pauseRedAlarm();
        }
        if(alarmCode == YELLOW_ALARM_CODE){
            //pauseYellowAlarm();
        }
    }
}

void AlarmSound::playRedAlarm()
{
    playRedAudio->setLoops(QSound::Infinite);
    playRedAudio->play();
    //playAudio->stop();
    //playRedAudio->isFinished();
    cout << "RED ALARM Sound Generated Successfully !!";
}

void AlarmSound::pauseRedAlarm()
{
    playRedAudio->stop();
    cout << "RED ALARM Sound Stopped Successfully !!" << playRedAudio->isFinished();
}

void AlarmSound::playYellowAlarm()
{
    playYellowAudio->setLoops(QSound::Infinite);
    playYellowAudio->play();
    //playAudio->stop();
    //playRedAudio->isFinished();
    cout << "YELLOW ALARM Sound Generated Successfully !!";
}

void AlarmSound::pauseYellowAlarm()
{
    playYellowAudio->stop();
    cout << "YELLOW ALARM Sound Stopped Successfully !!" << playRedAudio->isFinished();
}
