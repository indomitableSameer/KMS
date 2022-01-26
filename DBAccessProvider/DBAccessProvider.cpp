#include "DBAccessProvider.h"
#include <QSqlDatabase>
#include <ISqlTableList.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

CDBAccessProvider::CDBAccessProvider()
{
        QSqlDatabase dbtmp = QSqlDatabase::addDatabase("QSQLITE");
        db = new QSqlDatabase(dbtmp);
        // TODO : need to set proper location
        db->setDatabaseName("E:\\QtLearning\\KMS_T\\kml.db");
}

bool CDBAccessProvider::WriteSo2LevelToDB(int aSo2Value)
{
    QString prepareQuery = "insert into so2_level (date, time, value) VALUES (strftime('%Y-%m-%d', 'now'), strftime('%H:%M:%S','now')," + QString::number(aSo2Value) +")";
    return runQuery(prepareQuery);
}

bool CDBAccessProvider::WriteAlarmDataToDB(int alarm)
{
    QString prepareQuery = "insert into alarm_data (date, time, alarm) VALUES (strftime('%Y-%m-%d', 'now'), strftime('%H:%M:%S','now')," + QString::number(alarm) +")";
    return runQuery(prepareQuery);
}

bool CDBAccessProvider::WriteNotificationDataToDB(QString aNotificationMsg)
{
    QString prepareQuery = "insert into notification (date, time, msg) VALUES (strftime('%Y-%m-%d', 'now'), strftime('%H:%M:%S','now'), '" + aNotificationMsg +"')";
    return runQuery(prepareQuery);
}

void CDBAccessProvider::readSo2ValueRecords()
{

}

void CDBAccessProvider::readAlarmDataRecords()
{

}

void CDBAccessProvider::readNotificationDataRecords()
{

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
