#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <IDataReceiver.h>

class DataReceiver : public IDataReceiver
{
    Q_OBJECT
    QString m_csvLocation;
    QFile* m_file;
    QTextStream* m_stream;
    bool ValidateFileAccess();
    bool GetRowFromCsv(int& aSO2);
    void ReadDataPriodically();

public:
    DataReceiver(QString aCsvPath);
    virtual ~DataReceiver() {}
    bool start();
};

#endif // DATARECEIVER_H