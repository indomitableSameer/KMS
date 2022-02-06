#include "kms.h"
#include "ui_kms.h"

QString kms::widgetStyle = "";

void kms::graphupdate()
{

}

kms::kms(KMSLogic* logic, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kms)
{
    m_logic = logic;

    ui->setupUi(this);
    series = new QLineSeries();
    *series << QPointF(0 ,0);

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    // Customize series
    //    QPen pen(QRgb(0xfdb157));
    //    pen.setWidth(5);
    //    series->setPen(pen);

    // Customize chart title
    //    QFont font;
    //    font.setPixelSize(18);
    //    chart->setTitleFont(font);
    //    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitle("SO2 PPM vs Time");

    // Customize chart background
    //    QLinearGradient backgroundGradient;
    //    backgroundGradient.setStart(QPointF(0, 0));
    //    backgroundGradient.setFinalStop(QPointF(0, 1));
    //    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    //    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
    //    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    //chart->setBackgroundBrush(backgroundGradient);

    // Customize plot area background
    //    QLinearGradient plotAreaGradient;
    //    plotAreaGradient.setStart(QPointF(0, 1));
    //    plotAreaGradient.setFinalStop(QPointF(1, 0));
    //    plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
    //    plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
    //    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    //chart->setPlotAreaBackgroundBrush(plotAreaGradient);
    //chart->setPlotAreaBackgroundVisible(true);
    //![2]

    //![3]
    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();

    // Customize axis label font
    //    QFont labelsFont;
    //    labelsFont.setPixelSize(12);
    //    axisX->setLabelsFont(labelsFont);
    //    axisY->setLabelsFont(labelsFont);

    // Customize axis colors
    //    QPen axisPen(QRgb(0xd18952));
    //    axisPen.setWidth(1);
    //    axisX->setLinePen(axisPen);
    //    axisY->setLinePen(axisPen);

    // Customize axis label colors
    //    QBrush axisBrush(Qt::white);
    //    axisX->setLabelsBrush(axisBrush);
    //    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor("yellow")));
    //axisY->setShadesVisible(true);
    //![3]

    //![4]
    //
    axisX->append( "5 min", 5);
    axisX->append("10 min", 10);
    axisX->append("15 min", 15);
    axisX->append("20 min", 20);
    axisX->append("25 min", 25);
    axisX->append("30 min", 30);
    axisX->append("35 min", 35);
    axisX->append("40 min", 40);
    axisX->append("45 min", 45);
    axisX->append("50 min", 50);
    axisX->append("55 min", 55);
    axisX->append("60 min", 60);
    axisX->setRange(0, 60);


    axisY->append("0", 0);
    axisY->append("10000", 10000);
    axisY->append("15000", 15000);
    axisY->append("25000", 25000);
    axisY->setRange(0, 25000);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QVBoxLayout *layout = new QVBoxLayout(ui->chartframe);
    layout->addWidget(chartView);



    //![4]
    lcd = new QLCDNumber;
    lcd->display(0);
    //   QPalette palete =lcd->palette();
    // lcd->setAutoFillBackground(true); // see the different if you comment that line out.

    //    QPalette Pal = lcd->palette();
    //    Pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    //    Pal.setColor(QPalette::Normal, QPalette::Window, Qt::white);
    //    Pal.setColor(QPalette::Normal,QPalette::Background, Qt::white );


    //    lcd->setPalette(Pal);
    //  lcd->setMinimumSize(250,100);
    //lcd->setParent(ui->lcdframe);
    QVBoxLayout *layoutLCD = new QVBoxLayout(ui->lcdframe);
    layoutLCD->addWidget(lcd);
    //![5]
    //! plaintextedit settings
    //ui->plainTextEdit->setPlainText("");

    //QLine setting

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    widgetStyle = ui->frame->styleSheet();
}

kms::~kms()
{
    delete ui;
}

//int i =0;
void kms::DisplayProcessedData(IUiData aUiData)
{
    static QString style;
    *series << QPointF(aUiData.getDateTime().time().minute(), aUiData.getSo2Ppm());
    //*series << QPointF(i++, aUiData.getSo2Ppm());
    lcd->display(aUiData.getSo2Ppm());

    if(aUiData.getAlarm() == IAlarmType::RED)
    {
        ui->listWidget->insertItem(0, aUiData.getNotificationMsg());
        ui->frame->setStyleSheet("background-color: red");
    }
    else if(aUiData.getAlarm() == IAlarmType::YELLOW)
    {
        ui->listWidget->insertItem(0, aUiData.getNotificationMsg());
        ui->frame->setStyleSheet("background-color: yellow");
    }
    else
    {
        ui->frame->setStyleSheet(style);
    }
}


void kms::on_pushButton_clicked()
{

    if(ui->lineEdit->text()=="1234"){
        qDebug() << "Alarm Cancelled";
        IUiData aDate = m_logic->cancelAlarm();
        ui->listWidget->insertItem(0, aDate.getNotificationMsg());
    }
    ui->lineEdit->clear();
}
