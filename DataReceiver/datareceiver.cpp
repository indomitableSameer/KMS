#include "datareceiver.h"
#include <QFileInfo>
#include <QTextStream>
#include <QTimer>

#define DATA_READ_INTERVAL    60000

bool DataReceiver::ValidateFileAccess()
{
    QFileInfo aCsvfile(m_csvLocation);
    return aCsvfile.exists() && aCsvfile.isReadable() && aCsvfile.size()!=0;
}

bool DataReceiver::GetRowFromCsv(int& aSO2Value)
{
    QFile aCsvfile(m_csvLocation);
    if(!aCsvfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // file open failed.
        return false;
    }

    QTextStream in(&aCsvfile);
    QString line = in.readLine();

    // convert string to unsigned int
    bool ok;
    int test = line.toUInt(&ok);
    if(!ok)
    {
        // conversion failure
        return false;
    }

    aSO2Value = test;
    return true;
}

void DataReceiver::ReadDataPriodically()
{
    int so2;
    if(!GetRowFromCsv(so2))
    {
        // unable to get so2 value
        return;
    }
}

DataReceiver::DataReceiver(QString aCsvPath)
{
    if(aCsvPath.isNull() || aCsvPath.isEmpty())
    {
        throw std::_INVALID_ARGUMENT;
    }

    m_csvLocation = aCsvPath;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DataReceiver::ReadDataPriodically);
    timer->start(DATA_READ_INTERVAL);
}
