#ifndef NOTIFICATIONHANDLER_H
#define NOTIFICATIONHANDLER_H

#include <QQueue>
#include <IAlarmType.h>

class NotificationGenerator
{
private:
    QQueue<QString> notificationList;
public:
    NotificationGenerator();
    QString generateAlarmNotification(IAlarmType aAlarm, int probability);
    QString generateCancelNotification();
};

#endif // NOTIFICATIONHANDLER_H
