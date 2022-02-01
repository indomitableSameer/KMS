#include <alarmlogic.h>
#include <string>

using namespace std;

AlarmLogic::AlarmLogic()
{

}

IAlarmType AlarmLogic::CheckAlarmingSituation(int ppmLevel)
{
    // RED alarm has highest priority
    if (ppmLevel > redAlarmLevel)
    {
        m_activeAlarm = IAlarmType::RED;
    }
    // yellow alarm can not overrider red alarm
    if (m_activeAlarm !=IAlarmType::RED && ppmLevel > yellowAlarmLevel)
    {
        m_activeAlarm = IAlarmType::YELLOW;
    }
    // else set to none can not done. that can only be done when alarm is cancelled.

    return m_activeAlarm;
}

bool AlarmLogic::isAlarmActive()
{
    return m_activeAlarm != IAlarmType::NONE;
}

bool AlarmLogic::isRedAlarmActive()
{
    return m_activeAlarm != IAlarmType::RED;
}

bool AlarmLogic::isYellowAlarmActive()
{
    return m_activeAlarm != IAlarmType::YELLOW;
}

bool AlarmLogic::cancelAlarm()
{
    m_activeAlarm = IAlarmType::NONE;
    return m_activeAlarm == IAlarmType::NONE;
}

