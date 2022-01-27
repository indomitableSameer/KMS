#ifndef IDBREADER_H
#define IDBREADER_H

#include <ISqlTableList.h>
#include <QDateTime>
#include <QList>

struct so2_value_record
{
    QDate date;
    QTime time;
    int so2_value;
};

struct alarm_record
{
    QDate date;
    QTime time;
    int alarmCode;
};

struct notification_record
{
    QDate date;
    QTime time;
    QString msg;
};

class IDBReader
{
public:
    virtual QList<so2_value_record> readSo2ValueRecords(QDate* aSinceDate=NULL, QTime* aSinceTime=NULL, QDate* aTillDate=NULL, QTime* aTillTime=NULL) = 0;
    virtual QList<alarm_record> readAlarmDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime) = 0;
    virtual QList<notification_record> readNotificationDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime) = 0;
};

#endif // IDBREADER_H
