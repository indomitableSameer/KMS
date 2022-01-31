#ifndef CDBACCESSPROVIDER_H
#define CDBACCESSPROVIDER_H

#include <QObject>
#include <IDBWriter.h>
#include <QSqlDatabase>
#include <IDBReader.h>
#include <ISqlTableList.h>
#include <QueryEngine.h>

class CDBAccessProvider : public QObject, public IDBWriter, public IDBReader
{
    Q_OBJECT
    QSqlDatabase *db;
    QueryEngine *queryEngine;
    bool openDB();
    bool isDBOpen();
    void closeDB();
public:
    CDBAccessProvider();
    virtual ~CDBAccessProvider() {}
    bool WriteSo2LevelToDB(int aSo2Value);
    bool WriteAlarmDataToDB(int alarm);
    bool WriteNotificationDataToDB(QString aNotificationMsg);
    QList<so2_value_record> readSo2ValueRecords(QDate* aSinceDate=NULL, QTime* aSinceTime=NULL, QDate* aTillDate=NULL, QTime* aTillTime=NULL);
    QList<alarm_record> readAlarmDataRecords(QDate* aSinceDate=NULL, QTime* aSinceTime=NULL, QDate* aTillDate=NULL, QTime* aTillTime=NULL);
    QList<notification_record> readNotificationDataRecords(QDate* aSinceDate=NULL, QTime* aSinceTime=NULL, QDate* aTillDate=NULL, QTime* aTillTime=NULL);
};

#endif // CDBACCESSPROVIDER_H
