#ifndef ALARMLOGIC_H
#define ALARMLOGIC_H

#include <IAlarmType.h>

#define RED_ALARM_LEVEL   15000
#define YELLOW_ALARM_LEVEL    10000

class AlarmLogic
{

private:
    IAlarmType m_activeAlarm;
public:
    AlarmLogic();
    IAlarmType CheckAlarmingSituation(int ppmLevel);
    bool isAlarmActive();
    bool isRedAlarmActive();
    bool isYellowAlarmActive();
    bool cancelAlarm();
};

#endif // ALARMLOGIC_H
