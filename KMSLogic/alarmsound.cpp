#include "alarmsound.h"
#include <QSound>
#include <iostream>
//#include <qdebug.h>

AlarmSound::AlarmSound()
{

}

void AlarmSound::alarmSound()
{
    QSound *playAudio = new QSound("C:/Users/anish/QTProjects/KMS/alarm_red.wav");
    playAudio->setLoops(3);
    playAudio->play();
    //playAudio->stop();
    playAudio->isFinished();
    //qInfo() << "Sound Completed Successfully" << isFinished;

}


int main(){

    AlarmSound obj;
    obj.alarmSound();
    return 0;
}


//alarm sound functions

//read dummy sound and run it
