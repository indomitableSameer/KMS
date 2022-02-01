#ifndef ALARMSOUNDMANAGER_H
#define ALARMSOUNDMANAGER_H

#include <IAlarmType.h>
#include <QSound>

#define RED_ALARM_AUDIO_PATH    "E:\\QtLearning\\KMS_T\\resources\\sound\\red.wav"
#define YELLOW_ALARM_AUDIO_PATH "E:\\QtLearning\\KMS_T\\resources\\sound\\yellow.wav"

class AlarmSoundManager
{
private:
    bool m_isSoundOn;
    QSound* m_redAlarmSound;
    QSound* m_yellowAlarmSound;
    void playRedAlarm();
    void stopRedAlarm();
    void playYellowAlarm();
    void stopYellowAlarm();
public:
    AlarmSoundManager();
    void HandleAlarmSound(IAlarmType aAlarmType);
    bool isAlarmSoundOn();
    void stopAlarmSound();
};

#endif // ALARMSOUND_H
