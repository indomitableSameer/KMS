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
    void readSo2ValueRecords();
    void readAlarmDataRecords();
    void readNotificationDataRecords();
};

#endif // CDBACCESSPROVIDER_H
