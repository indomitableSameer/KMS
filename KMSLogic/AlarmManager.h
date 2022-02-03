#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

#include <AlarmLogic.h>
#include <AlarmSoundManager.h>

class AlarmManager
{
private:
    AlarmLogic* m_alarmLogic;
    AlarmSoundManager* m_alarmSoundManager;
public:
    AlarmManager();
    ~AlarmManager();
    IAlarmType HandlerAlarm(int so2ppm);
    bool cancelAlarm();
};

#endif // ALARMMANAGER_H
