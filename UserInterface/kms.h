#ifndef KMS_H
#define KMS_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <queue>
#include <IUiData.h>
#include <KmsLogic.h>

using namespace  QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class kms; }
QT_END_NAMESPACE

class kms : public QMainWindow
{
    Q_OBJECT

public slots:
    void graphupdate();

public:
    kms(KMSLogic* logic, QWidget *parent = nullptr);
    ~kms();
public slots:
    void DisplayProcessedData(IUiData aUiData);

private slots:
    void on_pushButton_clicked();
    //void on_lineEdit_editingFinished();

private:
    Ui::kms *ui;
    KMSLogic* m_logic;
    QLCDNumber* lcd;
private:
    QLineSeries *series;
    QChart *chart;
    QList<int> listSo2Level ;
    QLCDNumber* setupLcd();

};

#endif // KMS_H
