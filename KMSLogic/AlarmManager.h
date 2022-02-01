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
    bool HandlerAlarm(int so2ppm);
};

#endif // ALARMMANAGER_H
