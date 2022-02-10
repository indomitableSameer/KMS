#include <AlarmLogic.h>
#include <string>

using namespace std;

AlarmLogic::AlarmLogic()
{
    m_activeAlarm = IAlarmType::NONE;
}

/*
 *  Hazard Id : _H2.1_1_must_generate_alarm_
 *              _H3.1_must_generate_alarm_
 *              _H8.1_must_generate_alarm_
 */
IAlarmType AlarmLogic::CheckAlarmingSituation(int ppmLevel)
{
    // RED alarm has highest priority
    if (ppmLevel >= RED_ALARM_LEVEL)
    {
        m_activeAlarm = IAlarmType::RED;
    }
    // yellow alarm can not overrider red alarm
    if (m_activeAlarm !=IAlarmType::RED && ppmLevel >= YELLOW_ALARM_LEVEL)
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

