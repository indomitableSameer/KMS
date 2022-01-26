#ifndef ALARMSOUND_H
#define ALARMSOUND_H

class AlarmSound
{

private:

public:
    AlarmSound();
    void alarmSound(int alarmCode, bool alarmPlayPause);
    void playRedAlarm();
    void pauseRedAlarm();
    void playYellowAlarm();
    void pauseYellowAlarm();
};

#endif // ALARMSOUND_H
