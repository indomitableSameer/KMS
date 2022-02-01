#ifndef ALARMLOGIC_H
#define ALARMLOGIC_H

#include <IAlarmType.h>

const int redAlarmLevel = 15000;
const int yellowAlarmLevel =  10000;

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
