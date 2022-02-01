#ifndef KMS_H
#define KMS_H

#include <QMainWindow>


#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>



using namespace  QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class kms; }
QT_END_NAMESPACE

class kms : public QMainWindow
{
    Q_OBJECT

public:
    kms(QWidget *parent = nullptr);
    ~kms();

private:
    Ui::kms *ui;
};
#endif // KMS_H
