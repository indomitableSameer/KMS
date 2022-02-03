#ifndef IUIDATA_H
#define IUIDATA_H

#include <QString>
#include <QDateTime>
#include <IAlarmType.h>

class IUiData
{
    QDateTime dateTime;
    int so2ppmLevel;
    QString notification;
    IAlarmType alarm;

public:
    IUiData();
    void setDate(QDateTime aDateTime);
    void setSo2Ppm(int aSo2Ppm);
    void setNotification(QString aNotiMsg);
    void setAlarmType(IAlarmType aAlarm);

    QDateTime getDateTime();
    int getSo2Ppm();
    QString getNotificationMsg();
    IAlarmType getAlarm();
};

#endif // IUIDATA_H
