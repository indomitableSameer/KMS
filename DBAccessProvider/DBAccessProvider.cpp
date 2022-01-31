#include "DBAccessProvider.h"
#include <QSqlDatabase>
#include <ISqlTableList.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QueryEngine.h>

bool CDBAccessProvider::openDB()
{
    if(!db->open())
    {
        qInfo() << "ERROR : Opening database failed.";
        return false;
    }

    return true;
}

void CDBAccessProvider::closeDB()
{
    db->close();
}

CDBAccessProvider::CDBAccessProvider()
{
        QSqlDatabase dbtmp = QSqlDatabase::addDatabase("QSQLITE");
        db = new QSqlDatabase(dbtmp);
        // TODO : need to set proper location
        db->setDatabaseName("E:\\QtLearning\\KMS_T\\kml.db");
        queryEngine = new QueryEngine(db);
}

bool CDBAccessProvider::WriteSo2LevelToDB(int aSo2Value)
{
   bool aIsOpen = openDB();
   if(aIsOpen)
   {
       bool isSuccessFull = queryEngine->runQuery(QueryEngine::getInsertQuery(TABLE::SO2_LEVEL, QString::number(aSo2Value)));
       closeDB();
       return isSuccessFull;
   }
   return false;
}

bool CDBAccessProvider::WriteAlarmDataToDB(int alarm)
{
    bool aIsOpen = openDB();
    if(aIsOpen)
    {
        bool isSuccessFull = queryEngine->runQuery(QueryEngine::getInsertQuery(TABLE::ALARM_DATA, QString::number(alarm)));
        closeDB();
        return isSuccessFull;
    }
    return false;
}

bool CDBAccessProvider::WriteNotificationDataToDB(QString aNotificationMsg)
{
    bool aIsOpen = openDB();
    if(aIsOpen)
    {
        bool isSuccessFull = queryEngine->runQuery(QueryEngine::getInsertQuery(TABLE::NOTIFICATION_DATA, aNotificationMsg));
        closeDB();
        return isSuccessFull;
    }
    return false;
}

QList<so2_value_record> CDBAccessProvider::readSo2ValueRecords(QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime)
{
    QList<so2_value_record> recordList;
    openDB();
    queryEngine->runQuery(QueryEngine::getSelectQuery(TABLE::SO2_LEVEL, aSinceDate, aSinceTime, aTillDate, aTillTime));
    while (queryEngine->getNextRecord())
    {
       so2_value_record record;
       record.date = queryEngine->getColumnValue(0).toDate();
       record.time = queryEngine->getColumnValue(1).toTime();
       record.so2_value = queryEngine->getColumnValue(2).toInt();
       recordList.push_back(record);
    }

    closeDB();
    return recordList;
}

QList<alarm_record> CDBAccessProvider::readAlarmDataRecords(QDate *aSinceDate, QTime *aSinceTime, QDate *aTillDate, QTime *aTillTime)
{
    QList<alarm_record> recordList;
    openDB();
    QString query = QueryEngine::getSelectQuery(TABLE::ALARM_DATA, aSinceDate, aSinceTime, aTillDate, aTillTime);
    while (queryEngine->getNextRecord())
    {
       alarm_record record;
       record.date = queryEngine->getColumnValue(0).toDate();
       record.time = queryEngine->getColumnValue(1).toTime();
       record.alarmCode = queryEngine->getColumnValue(2).toInt();
       recordList.push_back(record);
    }

    closeDB();
    return recordList;
}

QList<notification_record> CDBAccessProvider::readNotificationDataRecords(QDate *aSinceDate, QTime *aSinceTime, QDate *aTillDate, QTime *aTillTime)
{
    QList<notification_record> recordList;
    openDB();
    QString query = QueryEngine::getSelectQuery(TABLE::NOTIFICATION_DATA, aSinceDate, aSinceTime, aTillDate, aTillTime);
    while (queryEngine->getNextRecord())
    {
       notification_record record;
       record.date = queryEngine->getColumnValue(0).toDate();
       record.time = queryEngine->getColumnValue(1).toTime();
       record.msg = queryEngine->getColumnValue(2).toString();
       recordList.push_back(record);
    }

    closeDB();
    return recordList;
}
