#ifndef KMS_H
#define KMS_H

#include <KmsLogic.h>
#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <IUiData.h>
#include <queue>

using namespace  QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class kms; }
QT_END_NAMESPACE

class kms : public QMainWindow
{
    Q_OBJECT

public:
    kms(KMSLogic* logic, QWidget *parent = nullptr);
    ~kms();

public slots:
    void DisplayProcessedData(IUiData aUiData);

private slots:
    void on_pushButton_clicked();

private:
    Ui::kms *ui;

private:
    QLineSeries *series;
    KMSLogic* m_logic;
    QChart *chart;
    QLCDNumber *lcd;
    QList<int> listSo2Level;
    static QString widgetStyle;

};
#endif // KMS_H
