#include <DataReceiver.h>
#include <QFileInfo>
#include <QTextStream>
#include <QTimer>
#include <QDebug>
#include <stdexcept>

#define DATA_READ_INTERVAL    30000

bool DataReceiver::ValidateFileAccess()
{
    QFileInfo aCsvfile(m_csvLocation);
    return aCsvfile.exists() && aCsvfile.isReadable() && aCsvfile.size()!=0;
}

bool DataReceiver::GetRowFromCsv(int& aSO2Value)
{
    if(m_stream->atEnd())
    {
        qDebug() << "INFO: read full file, restarting from start again.";
        delete m_stream;
        m_file->close();
        delete m_file;
        start();
    }

    QString line = m_stream->readLine();

    // convert string to unsigned int
    bool ok;
    int test = line.toUInt(&ok);
    if(!ok)
    {
        // conversion failure
        qDebug() << "ERROR: toUInt() Failed.";
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
        qDebug() << "ERROR: Unable to get row from csv file.";
        return;
    }
    emit dataAvailable(so2);
}

DataReceiver::DataReceiver(QString aCsvPath)
{
    if(aCsvPath.isNull() || aCsvPath.isEmpty())
    {
        qDebug() << "ERROR: Invalid Argument to DataReceiver constructor " << aCsvPath;
        throw std::invalid_argument("path is not valid");

    }

    m_csvLocation = aCsvPath;
}

bool DataReceiver::start()
{
    m_file = new QFile(m_csvLocation);
    if(!m_file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // file open failed.
        qDebug() << "ERROR: Unable to open file " << m_csvLocation;
        return false;
    }

    m_stream = new QTextStream(m_file);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DataReceiver::ReadDataPriodically);
    timer->start(DATA_READ_INTERVAL);
    return true;
}
