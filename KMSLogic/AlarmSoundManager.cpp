#include "AlarmSoundManager.h"
#include <QSound>
#include <iostream>
#include <string>

using namespace std;

AlarmSoundManager::AlarmSoundManager()
{
    m_redAlarmSound = new QSound(RED_ALARM_AUDIO_PATH);
    m_yellowAlarmSound = new QSound(YELLOW_ALARM_AUDIO_PATH);
    if(m_redAlarmSound == NULL || m_yellowAlarmSound == NULL)
    {
        throw std::runtime_error("Failed to create QSoundObject");
    }
}

/*
 *  Hazard Id : _H2.1_2_must_generate_alarm_
 *              _H10.2_distinctive_sound_
*/
void AlarmSoundManager::HandleAlarmSound(IAlarmType aAlarmType)
{
    if(aAlarmType == IAlarmType::RED)
    {
        playRedAlarm();
        stopYellowAlarm();
        m_isSoundOn = true;
    }
    else if(aAlarmType != IAlarmType::RED && aAlarmType == IAlarmType::YELLOW)
    {
        playYellowAlarm();
        m_isSoundOn = true;
    }
}

bool AlarmSoundManager::isAlarmSoundOn()
{
    return m_isSoundOn;
}

void AlarmSoundManager::stopAlarmSound()
{
    stopRedAlarm();
    stopYellowAlarm();
}

void AlarmSoundManager::playRedAlarm()
{
    m_redAlarmSound->setLoops(QSound::Infinite);
    m_redAlarmSound->play();
}

void AlarmSoundManager::stopRedAlarm()
{
    m_redAlarmSound->stop();
    m_isSoundOn = false;
}

void AlarmSoundManager::playYellowAlarm()
{
    m_yellowAlarmSound->setLoops(QSound::Infinite);
    m_yellowAlarmSound->play();
}

void AlarmSoundManager::stopYellowAlarm()
{
    m_yellowAlarmSound->stop();
    m_isSoundOn = false;
}
