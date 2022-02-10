#include <NotificationGenerator.h>
#include <QDateTime>

NotificationGenerator::NotificationGenerator()
{
}

/*
 * Hazard id : _H5.1_append_so2ppm_
*/
QString NotificationGenerator::generateAlarmNotification(IAlarmType aAlarm, int so2ppm, int probability)
{
    QString msg;
    msg.clear();
    if(aAlarm == IAlarmType::RED)
    {
        QDateTime local(QDateTime::currentDateTime());
        msg = local.date().toString("dd.MM.yyyy") + " " + local.time().toString("hh:mm:ss");
        msg = msg + " CRITICAL!!! RED Alarm!! SO2PPM=" + QString::number(so2ppm)+ " Blockage Probabity= " +  QString::number(probability);
    }
    else if(aAlarm == IAlarmType::YELLOW)
    {
        QDateTime local(QDateTime::currentDateTime());
        msg = local.date().toString("dd.MM.yyyy") + " " + local.time().toString("hh:mm:ss");
        msg = msg + " ALERT !!! YELLOW Alarm!! SO2PPM=" + QString::number(so2ppm)+ " Blockage Probabity = " +  QString::number(probability);
    }

    notificationList.enqueue(msg);
    return msg;
}

QString NotificationGenerator::generateCancelNotification()
{
    QDateTime local(QDateTime::currentDateTime());
    QString msg = local.date().toString("dd.MM.yyyy") + " " + local.time().toString("hh:mm:ss") + " Alarm cancelled by @Admin";
    return msg;
}


