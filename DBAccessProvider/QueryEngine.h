#ifndef QUERYENGINE_H
#define QUERYENGINE_H

#include <QDateTime>
#include <QString>
#include <ISqlTableList.h>
#include <QSqlDatabase>
#include <QSqlQuery>

class QueryEngine
{
private:
    QSqlDatabase *db;
    QSqlQuery* query;
    static QString getCurrentDate();
    static QString getCurrentTime();
    static QString generateWhereClause(QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime);
public:
    QueryEngine(QSqlDatabase* aDbFileObject);
    static QString getInsertQuery(TABLE aTable, QString value);
    static QString getSelectQuery(TABLE aTable, QDate* aSinceDate, QTime* aSinceTime, QDate* aTillDate, QTime* aTillTime);
    bool runQuery(QString aQuery);
    bool getNextRecord();
    QVariant getColumnValue(int aColumn);
};

#endif // QUERYENGINE_H
