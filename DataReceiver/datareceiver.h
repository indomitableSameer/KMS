#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QString>

class DataReceiver : public QObject
{
    Q_OBJECT
    QString m_csvLocation;
    bool ValidateFileAccess();
    bool GetRowFromCsv(int& aSO2);
    void ReadDataPriodically();
public:
    DataReceiver(QString aCsvPath);

    virtual ~DataReceiver() {}
};

#endif // DATARECEIVER_H
