#include "kms.h"
#include "ui_kms.h"

void kms::graphupdate()
{

}

kms::kms(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kms)
{
//    ui->setupUi(this);


    ui->setupUi(this);
    //![1]
    foreach(auto &x,listSo2Level)
        qDebug()<<x;


    series = new QLineSeries();
//    *series << QPointF(0, listSo2Level[0]) << QPointF(9, listSo2Level[1]) << QPointF(15, listSo2Level[2]) << QPointF(25, listSo2Level[3]) << QPointF(29, listSo2Level[4]);
    *series << QPointF(0 ,0); //, listSo2Level[0]) << QPointF(9, listSo2Level[1]) << QPointF(15, listSo2Level[2]) << QPointF(25, listSo2Level[3]) << QPointF(29, listSo2Level[4]);

    chart = new QChart();
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
        axisPen.setWidth(1);
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
        axisX->setRange(0, 65);


        axisY->append("Normal", 9999);
        axisY->append("Yellow", 14999);
        axisY->append("Red", 20000);
        axisY->setRange(0, 20000);

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
           Pal.setColor(QPalette::Normal, QPalette::Window, Qt::white);
           Pal.setColor(QPalette::Normal,QPalette::Background, Qt::white );


           lcd->setPalette(Pal);
      //  lcd->setMinimumSize(250,100);
        //lcd->setParent(ui->lcdframe);
        QVBoxLayout *layoutLCD = new QVBoxLayout(ui->lcdframe);
        layoutLCD->addWidget(lcd);
    //![5]
    //! plaintextedit settings
     ui->plainTextEdit->setPlainText("tomatoes are expensive");

     //QLine setting

     ui->lineEdit->setEchoMode(QLineEdit::Password);





}

kms::~kms()
{
    delete ui;
}


void kms::on_pushButton_clicked()
{

   //below is series for graph
    series ->clear();
    listSo2Level.append(2000);

 //   qInfo() << listSo2Level.size();

    if(listSo2Level.size()>12){                   //in case array size is above 12 which is our X axis max capacity
     foreach(auto &x,listSo2Level)        //it will delete all list elements except the newest one
     {
          if(listSo2Level.size() != 1){
             listSo2Level.removeFirst();
         }
     }
    }
    qInfo() << listSo2Level.size();
    switch(listSo2Level.size()){
    case 0:
        break;
    case 1:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]);
        break;
    case 2:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1]);
     break;
    case 3:
        *series << QPointF(0, 0) << QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1]) << QPointF(15, listSo2Level[2]);
     break;
    case 4:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2]) << QPointF(20, listSo2Level[3]);
     break;
    case 5:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4]);
     break;
    case 6:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]);
     break;
    case 7:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6]);
     break;
    case 8:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
                << QPointF(40, listSo2Level[7]);
        break;
    case 9:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
                << QPointF(40, listSo2Level[7])<< QPointF(45, listSo2Level[8]);
        break;
    case 10:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
                << QPointF(40, listSo2Level[7])<< QPointF(45, listSo2Level[8])<< QPointF(50, listSo2Level[9]);
        break;
    case 11:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
                << QPointF(40, listSo2Level[7])<< QPointF(45, listSo2Level[8])<< QPointF(50, listSo2Level[9])<< QPointF(55, listSo2Level[10]);
        break;
    case 12:
        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
                << QPointF(40, listSo2Level[7])<< QPointF(45, listSo2Level[8])<< QPointF(50, listSo2Level[9])<< QPointF(55, listSo2Level[10])<< QPointF(60, listSo2Level[11]);
     break;
   default:

//         //appending new value of S02 here coming from slotginal thingi
//        *series << QPointF(0, 0)<< QPointF(5, listSo2Level[0]) << QPointF(10, listSo2Level[1])<< QPointF(15, listSo2Level[2])<< QPointF(20, listSo2Level[3]) << QPointF(25, listSo2Level[4])<< QPointF(30, listSo2Level[5]) << QPointF(35, listSo2Level[6])
//                << QPointF(40, listSo2Level[7])<< QPointF(45, listSo2Level[8])<< QPointF(50, listSo2Level[9])<< QPointF(55, listSo2Level[10])<< QPointF(60, listSo2Level[11]);
    break;


}
    //Below is the way to update text
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText("Tomatoes & Potatoes are not expensive");
}


void kms::on_lineEdit_editingFinished()
{

     if(ui->lineEdit->text()=="secretkey"){
        qInfo()<< "Correct Key";
     }
}

