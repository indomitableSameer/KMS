#ifndef KMS_H
#define KMS_H

#include <QMainWindow>


#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>

#include <queue>



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
    kms(QWidget *parent = nullptr);  
    ~kms();



private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::kms *ui;

private:
QLineSeries *series;
QChart *chart;
QList<int> listSo2Level ;

};
#endif // KMS_H
