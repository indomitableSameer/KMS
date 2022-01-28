#include <QueryEngine.h>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

QueryEngine::QueryEngine(QSqlDatabase* aDbFileObject)
{
    if(aDbFileObject == NULL)
    {
        throw std::_INVALID_ARGUMENT;
    }

    db = aDbFileObject;
    query = new QSqlQuery();
}

QString QueryEngine::getCurrentDate()
{
    QDateTime local(QDateTime::currentDateTime());
    return local.date().toString("dd.MM.yyyy");
}

QString QueryEngine::getCurrentTime()
{
    QDateTime local(QDateTime::currentDateTime());
    return local.time().toString();
}

QString QueryEngine::generateWhereClause(QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime)
{
    QString whereClause;
    if((aSinceDate != NULL && aSinceDate->isValid()) ||
            (aSinceTime != NULL && aSinceTime->isValid()) ||
            (aTillDate != NULL && aTillDate->isValid()) ||
            (aTillTime != NULL && aTillTime->isValid()))
    {
        whereClause = "where ";
    }

    if(aSinceDate != NULL && aSinceDate->isValid() == true)
    {
        whereClause = whereClause + "date > '" + aSinceDate->toString("dd.MM.yyyy") +"'";
    }

    if(aTillDate != NULL && aTillDate->isValid() == true)
    {
        whereClause = whereClause + " and date < '" + aTillDate->toString("dd.MM.yyyy") +"'";
    }

    return whereClause;
}

QString QueryEngine::getInsertQuery(TABLE aTable, QString value)
{
    QString prepareQuery;
    switch (aTable)
    {
        case TABLE::SO2_LEVEL:
        prepareQuery = "insert into so2_level (date, time, value) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"'," + value +")";
        break;

        case TABLE::ALARM_DATA:
        prepareQuery = "insert into alarm_data (date, time, alarm) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"'," + value +")";
        break;

        case TABLE::NOTIFICATION_DATA:
        prepareQuery = "insert into notification (date, time, msg) VALUES ('" + getCurrentDate() + "','" + getCurrentTime() +"','" + value +"')";
        break;
    }
    return prepareQuery;
}

QString QueryEngine::getSelectQuery(TABLE aTable, QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime)
{
    QString prepareQuery;
    switch (aTable)
    {
        case TABLE::SO2_LEVEL:
        prepareQuery = "select * from so2_level" + generateWhereClause(aSinceDate, aSinceTime, aTillDate, aTillTime);
        break;

        case TABLE::ALARM_DATA:
        prepareQuery = "select * from alarm_data" + generateWhereClause(aSinceDate, aSinceTime, aTillDate, aTillTime);
        break;

        case TABLE::NOTIFICATION_DATA:
        prepareQuery = "select * from notification" + generateWhereClause(aSinceDate, aSinceTime, aTillDate, aTillTime);
        break;
    }

    return prepareQuery;
}

bool QueryEngine::runQuery(QString aQuery)
{
    query->clear();
    bool ret = query->exec(aQuery);

    if(!ret)
    {
        // Error while running query, log error
        qInfo() << "ERROR :" << query->lastError();
    }

    return ret;
}

bool QueryEngine::getNextRecord()
{
    return query->next();
}

QVariant QueryEngine::getColumnValue(int aColumnValue)
{
    return query->value(aColumnValue);
}
