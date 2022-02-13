#include <AlarmManager.h>
#include <IAlarmType.h>
#include <QtDebug>

AlarmManager::AlarmManager()
{
    m_alarmLogic = new AlarmLogic();
    m_alarmSoundManager = new AlarmSoundManager();
}

AlarmManager::~AlarmManager()
{
    delete m_alarmLogic;
    delete m_alarmSoundManager;
}

IAlarmType AlarmManager::HandlerAlarm(int so2ppm)
{
    IAlarmType aAlarm = m_alarmLogic->CheckAlarmingSituation(so2ppm);
    if(aAlarm == IAlarmType::NONE)
    {
        qDebug() << "No Alarm raised..";
        return IAlarmType::NONE;
    }

    qDebug() << "Alarm Raised.." ;
    m_alarmSoundManager->HandleAlarmSound(aAlarm);
    return aAlarm;
}

bool AlarmManager::cancelAlarm()
{
    if(m_alarmLogic->isAlarmActive())
    {
        m_alarmLogic->cancelAlarm();
        m_alarmSoundManager->stopAlarmSound();
        return true;
    }
    return false;
}
