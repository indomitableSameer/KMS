#include <IUiData.h>

IUiData::IUiData()
{
    alarm = IAlarmType::NONE;
    so2ppmLevel = 0;
    notification = "";
}

void IUiData::setDate(QDateTime aDateTime)
{
    dateTime = aDateTime;
}

void IUiData::setSo2Ppm(int aSo2Ppm)
{
    so2ppmLevel = aSo2Ppm;
}

void IUiData::setNotification(QString aNotiMsg)
{
    notification = aNotiMsg;
}

void IUiData::setAlarmType(IAlarmType aAlarm)
{
    alarm = aAlarm;
}

QDateTime IUiData::getDateTime()
{
    return dateTime;
}

int IUiData::getSo2Ppm()
{
    return so2ppmLevel;
}

QString IUiData::getNotificationMsg()
{
    return notification;
}

IAlarmType IUiData::getAlarm()
{
    return alarm;
}
