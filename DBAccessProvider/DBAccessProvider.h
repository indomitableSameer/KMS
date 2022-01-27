#ifndef CDBACCESSPROVIDER_H
#define CDBACCESSPROVIDER_H

#include <QObject>
#include <IDBWriter.h>
#include <QSqlDatabase>
#include <IDBReader.h>
#include <ISqlTableList.h>

class CDBAccessProvider : public QObject, public IDBWriter, public IDBReader
{
    Q_OBJECT
    QSqlDatabase *db;
    bool openDB();
    bool isDBOpen();
    void close();
    bool runQuery(QString aQuery);
public:
    CDBAccessProvider();
    virtual ~CDBAccessProvider() {}
    bool WriteSo2LevelToDB(int aSo2Value);
    bool WriteAlarmDataToDB(int alarm);
    bool WriteNotificationDataToDB(QString aNotificationMsg);
    QList<so2_value_record> readSo2ValueRecords(QDate* aSinceDate=NULL, QTime* aSinceTime=NULL, QDate* aTillDate=NULL, QTime* aTillTime=NULL);
    QList<alarm_record> readAlarmDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime);
    QList<notification_record> readNotificationDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime);
};

#endif // CDBACCESSPROVIDER_H
