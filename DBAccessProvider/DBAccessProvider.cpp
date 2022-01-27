#include "DBAccessProvider.h"
#include <QSqlDatabase>
#include <ISqlTableList.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

QString getCurrentDate()
{
    QDateTime local(QDateTime::currentDateTime());
    return local.date().toString("dd.MM.yyyy");
}

QString getCurrentTime()
{
    QDateTime local(QDateTime::currentDateTime());
    return local.time().toString();
}

CDBAccessProvider::CDBAccessProvider()
{
        QSqlDatabase dbtmp = QSqlDatabase::addDatabase("QSQLITE");
        db = new QSqlDatabase(dbtmp);
        // TODO : need to set proper location
        db->setDatabaseName("E:\\QtLearning\\KMS_T\\kml.db");
}

bool CDBAccessProvider::WriteSo2LevelToDB(int aSo2Value)
{
    QString prepareQuery = "insert into so2_level (date, time, value) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"'," + QString::number(aSo2Value) +")";
    return runQuery(prepareQuery);
}

bool CDBAccessProvider::WriteAlarmDataToDB(int alarm)
{
    QString prepareQuery = "insert into alarm_data (date, time, alarm) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"'," + QString::number(alarm) +")";
    return runQuery(prepareQuery);
}

bool CDBAccessProvider::WriteNotificationDataToDB(QString aNotificationMsg)
{
    QString prepareQuery = "insert into notification (date, time, msg) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"'," + aNotificationMsg +"')";
    return runQuery(prepareQuery);
}

QList<so2_value_record> CDBAccessProvider::readSo2ValueRecords(QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime)
{
    if(!db->open())
    {
        qInfo() << "ERROR : Opening database failed.";
        //return false;
    }
    QList<so2_value_record> recordList;
    QString prepareQuery = "select * from so2_level";
    QSqlQuery query;
    query.exec(prepareQuery);
    qDebug() << "QueryExecuted : " << prepareQuery << query.lastError();

    while (query.next())
    {
       so2_value_record record;
       record.date = query.value(0).toDate();
       record.time = query.value(0).toTime();
       record.so2_value = query.value(2).toInt();
       recordList.push_back(record);
    }
    db->close();
    return recordList;
}

QList<alarm_record> CDBAccessProvider::readAlarmDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime)
{
    QList<alarm_record> records;
    return records;
}

QList<notification_record> CDBAccessProvider::readNotificationDataRecords(QDate aSinceDate, QTime aSinceTime, QDate aTillDate, QTime aTillTime)
{
    QList<notification_record> records;
    return records;
}

bool CDBAccessProvider::runQuery(QString aQuery)
{
    if(!db->open())
    {
        qInfo() << "ERROR : Opening database failed.";
        return false;
    }

    QSqlQuery query(aQuery);
    bool ret = query.exec();

    if(!ret)
    {
        // Error while running query, log error
        qInfo() << "ERROR :" << query.lastError();
    }

    db->close();
    return ret;
}
