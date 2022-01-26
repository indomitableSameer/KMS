#ifndef ALARMSOUND_H
#define ALARMSOUND_H

#include <string.h>

using namespace std;

class AlarmSound
{

private:
    String RED_ALARM_AUDIO_PATH = "ffs";
    string YELLOW_ALARM_AUDIO_PATH = "sffs";


public:
    AlarmSound();
    //declare function for Alarm Sound

    void alarmSound(int alarmCode, bool alarmPlayPause);
    void playRedAlarm();
    void pauseRedAlarm();
    void playYellowAlarm();
    void pauseYellowAlarm();
};

#endif // ALARMSOUND_H
