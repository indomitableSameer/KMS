#include <NotificationGenerator.h>
#include <QDateTime>

NotificationGenerator::NotificationGenerator()
{
}

QString NotificationGenerator::generateAlarmNotification(IAlarmType aAlarm, int probability)
{
    QString msg;
    msg.clear();
    if(aAlarm == IAlarmType::RED)
    {
        QDateTime local(QDateTime::currentDateTime());
        msg = local.date().toString("dd.MM.yyyy");
        msg = " CRITICAL!!! RED Alarm!! Blockage Probabity = " +  QString::number(probability);
    }
    else if(aAlarm == IAlarmType::YELLOW)
    {
        QDateTime local(QDateTime::currentDateTime());
        msg = local.date().toString("dd.MM.yyyy");
        msg = " ALERT !!! YELLOW Alarm!! Blockage Probabity = " +  QString::number(probability);
    }

    notificationList.enqueue(msg);
    return msg;
}

QString NotificationGenerator::generateCancelNotification()
{
    QDateTime local(QDateTime::currentDateTime());
    QString msg = local.date().toString("dd.MM.yyyy") + " Alarm cancelled by @Admin";
    return msg;
}


