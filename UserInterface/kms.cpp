#include "kms.h"
#include "ui_kms.h"

kms::kms(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kms)
{
    ui->setupUi(this);


    ui->setupUi(this);
    //![1]
        QLineSeries *series = new QLineSeries();
        *series << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
    //![1]

    //![2]
        // Customize series
        QPen pen(QRgb(0xfdb157));
        pen.setWidth(5);
        series->setPen(pen);

        // Customize chart title
        QFont font;
        font.setPixelSize(18);
        chart->setTitleFont(font);
        chart->setTitleBrush(QBrush(Qt::white));
        chart->setTitle("Customchart example");

        // Customize chart background
        QLinearGradient backgroundGradient;
        backgroundGradient.setStart(QPointF(0, 0));
        backgroundGradient.setFinalStop(QPointF(0, 1));
        backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
        backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
        backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        chart->setBackgroundBrush(backgroundGradient);

        // Customize plot area background
        QLinearGradient plotAreaGradient;
        plotAreaGradient.setStart(QPointF(0, 1));
        plotAreaGradient.setFinalStop(QPointF(1, 0));
        plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
        plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
        plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        chart->setPlotAreaBackgroundBrush(plotAreaGradient);
        chart->setPlotAreaBackgroundVisible(true);
    //![2]

    //![3]
        QCategoryAxis *axisX = new QCategoryAxis();
        QCategoryAxis *axisY = new QCategoryAxis();

        // Customize axis label font
        QFont labelsFont;
        labelsFont.setPixelSize(12);
        axisX->setLabelsFont(labelsFont);
        axisY->setLabelsFont(labelsFont);

        // Customize axis colors
        QPen axisPen(QRgb(0xd18952));
        axisPen.setWidth(2);
        axisX->setLinePen(axisPen);
        axisY->setLinePen(axisPen);

        // Customize axis label colors
        QBrush axisBrush(Qt::white);
        axisX->setLabelsBrush(axisBrush);
        axisY->setLabelsBrush(axisBrush);

        // Customize grid lines and shades
        axisX->setGridLineVisible(false);
        axisY->setGridLineVisible(false);
        axisY->setShadesPen(Qt::NoPen);
        axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
        axisY->setShadesVisible(true);
    //![3]

    //![4]
    //
        axisX->append( "Monday", 0);
        axisX->append("Tuesday", 10);
        axisX->append("Wednesday", 15);
        axisX->append("Thursday", 20);
        axisX->append("Friday", 25);
        axisX->append("Saturday", 30);
        axisX->append("Sunday", 35);
        axisX->setRange(0, 35);


        axisY->append("Normal", 10);
        axisY->append("Yellow", 20);
        axisY->append("Red", 30);
        axisY->setRange(0, 30);

        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
        series->attachAxis(axisY);
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        //stackoverflolwbelow
        QVBoxLayout *layout = new QVBoxLayout(ui->chartframe);
        layout->addWidget(chartView);



    //![4]
        QLCDNumber *lcd = new QLCDNumber;
        lcd->display(1501);
     //   QPalette palete =lcd->palette();
       // lcd->setAutoFillBackground(true); // see the different if you comment that line out.
              QWidget:: autoFillBackground();
           QPalette Pal = lcd->palette();
           Pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
           Pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
           lcd->setPalette(Pal);
      //  lcd->setMinimumSize(250,100);
        //lcd->setParent(ui->lcdframe);
        QVBoxLayout *layoutLCD = new QVBoxLayout(ui->lcdframe);
        layoutLCD->addWidget(lcd);
    //![5]

}

kms::~kms()
{
    delete ui;
}

