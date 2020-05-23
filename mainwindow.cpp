#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "connectdialog.h" // connectdialog zawiera okno do obsługi komunikacji z kontrolerem
#include <QSerialPortInfo>


#include <QDebug>


=======

#include "connectdialog.h" // connectdialog zawiera okno do obsługi komunikacji z kontrolerem
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>

#include <QDate>

#include <QDebug>

>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    this->device = new QSerialPort;
    insert_image();
    setup_plants();
    createChart();
=======
    qDebug() << "Did connect for test button work?" << connect(ui->test_button,SIGNAL(clicked()), this, SLOT(myCustomSlot()));
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
}

MainWindow::~MainWindow()
{
    delete ui;
<<<<<<< HEAD
    delete device;
}


void MainWindow::on_exit_button_clicked()
{
    qDebug() << "Exit button has been clicked \n Exiting the application";
    QApplication::quit();

}



void MainWindow::myCustomSlot(){
    qDebug() << "Test button pushed";
}

int MainWindow::on_connectButton_clicked()
=======
}

void MainWindow::on_exit_button_clicked()
{
    qDebug() << "Exit button has been clicked \n Exiting the application";
}


void MainWindow::on_exit_button_pressed()
{
    qDebug() << "Exit button has been pressed \n Not exiting the application";
}


void MainWindow::on_connectButton_clicked()
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
{
    /*
     * W przypadku tworzenia drugiego okna w taki sposób, gdy już okno zostanie otwarte,
     * nie bedziemy w stanie powrócić do main window. Czyli cały program czeka na decyzje
     * wychodzącą z connect dialog.
     * */

//    ConnectDialog dialogWindow;
//    dialogWindow.setModal(true);
//    dialogWindow.exec();


    /* Drugi przypadek jest lepszy ze względu na możliwość dalszej pracy nad pierwszym oknem main window,
     * mimo że nie dokonaliśmy ostatecznej decyzji w oknie dialog. */

    secondConnectionWindow = new ConnectDialog(this);
    secondConnectionWindow->show();
<<<<<<< HEAD
    connect(secondConnectionWindow, SIGNAL(readFromPort()) , this, SLOT(get_device_name()));
    ui->main_text->append("New connection in progress..");
    return 1;
}

void MainWindow::get_device_name()
{
    qInfo() << secondConnectionWindow->device_num.device_name_x;
    QString dev_m = secondConnectionWindow->device_num.device_name_x;

    if (dev_m.contains('"')){
        dev_m.replace('"',"");
        qInfo() << "Wrong device name";
    }

    this->device->setPortName(dev_m);
    ui->device_edit->append(dev_m);
    qInfo() << "Port name given to set :" << dev_m;
    if(device->open(QSerialPort::ReadOnly)){
        device->setBaudRate(QSerialPort::Baud9600);
        device->setDataBits(QSerialPort::Data8);
        device->setParity(QSerialPort::NoParity);
        device->setStopBits(QSerialPort::OneStop);
        device->setFlowControl(QSerialPort::NoFlowControl);
        QString line = this->device->readAll();
        qDebug() << line;
        ui->main_text->append(line);
        connect(this->device,SIGNAL(readyRead()), this, SLOT(readFromPort()));
    }
    else{
            qInfo() << "Could not open port";
        }
}

void MainWindow::readFromPort()
{
    QElapsedTimer timer;
    timer.start();
    while(this->device->canReadLine()){
          QString line = this->device->readAll();
//          ui->main_text->append(line);
          QStringList word = line.split("\t");
          QStringList goal;
          for (int i=0; i < word.length() ; i++){
              qInfo() << word.at(i);
                if(word.at(i).contains("S")){
                    temp = word[i+1].toFloat();
                    ui->tempLCD->display(temp);
                    push_data_to_series(temp,timer);
                    qInfo() << temp << "TEMPERATURA";
                    hum = word[i+2].toFloat();
                    ui->humLCD->display(hum);
                    qInfo() << hum << "WILGOTNOSC";
                    lux = word[i+3].toFloat();
                    ui->luxLCD->display(lux);
                    qInfo() << lux << "LUXY";
                }
          }
    }
}

void MainWindow::readTemp()
{
    while(this->device->canReadLine()){
          QString line = this->device->readLine();
          if(line.contains('S')){
              qInfo() << " START";
          }
    }

}

void MainWindow::insert_image()
{
    QPixmap pixmap("/home/maroine/Desktop/19hoursago/QTPlantStatus-d8d02d61a821b99374eb60dd7f7f6ef5a9d0f1d9/src/dobra.png");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::setup_plants()
{
    ui->comboBox->addItem("Plant 1");
    ui->comboBox->addItem("Plant 2");
    ui->comboBox->addItem("Plant 3");
}

void MainWindow::push_data_to_series(float tempx, QElapsedTimer timer)
{

//    QDateTime xValue = QDateTime::currentDateTime();
//    // first x value = xValue.toMSecsSinceEpoch()
//    series->append(timer.elapsed()/1000,tempx);
//    chart->addSeries(series);
      double now = QDateTime::currentDateTime().toTime_t();
      ui->plot->graph(0)->addData(now,tempx);
      ui->plot->xAxis->setRange(now+0.25,8,Qt::AlignRight);
//      ui->plot->yAxis->setRange(tempx+0.25,0.40,Qt::AlignRight);
      ui->plot->replot();
}




void MainWindow::on_getdata_clicked()
{

    get_device_name();
    readTemp();
//    readFromPort();
}






void MainWindow::createChart()
{
//    chart->addSeries(series);
//    chart->setTitle("Wykres series");
//    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis();
//    axisX->setRange(0,2000);
//    axisX->setLabelFormat("%g");
//    axisX->setTitleText("Czas [s]");

//    QtCharts::QValueAxis *axisy = new QtCharts::QValueAxis();
//    axisX->setRange(10,30);
//    axisX->setTitleText("Temperatura [C]");

//    chart->addAxis(axisX,Qt::AlignBottom);
//    series->attachAxis(axisX);

//    chart->addAxis(axisy,Qt::AlignLeft);
//    series->attachAxis(axisy);

//    chart->setTitle("Pomiar temperatury");
//    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
////    QVBoxLayout *layout = new QVBoxLayout(this);

////    layout->addWidget(chartView);

//////    chartView->setRenderHint(QPainter::Antialiasing);
//////    ui->centralwidget = new QWidget(this);
//////            this->setCentralWidget(ui->centralwidget);
//    gridLayout = new QGridLayout(ui->label);
////    gridLayout->addWidget(chartView);
//    gridLayout->addWidget(chartView,1,2);

    double now = QDateTime::currentDateTime().toTime_t();
    // QCUSTOM PLOT ŚCIEŻKA
    //tworzenie zwykłego wykresu
    ui->plot->setLocale(QLocale(QLocale::Polish,QLocale::Poland));
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue));
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
//    // timer
    QSharedPointer <QCPAxisTickerDateTime> dateTicker (new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss:z");
    ui->plot->xAxis->setTicker(dateTicker);

    // qcustomplot


    //dodawanie do wykresu wartości wygenerowanych wektorów x-y
    ui->plot->xAxis->setRange(0,now+24*3600*249);
    ui->plot->yAxis->setRange(15,30);



}



=======
    if(secondConnectionWindow){
        qInfo() << "Otwarto nowe okno";
            ui->main_text->append("New connection in progress..");
    }
}



//void ConnectDialog::readFromPort()
//{
//    while(this->device->canReadLine()){
//          QString line = this->device->readAll();
//          qDebug() << line;
//          QString terminator = "\r";
//          int pos = line.lastIndexOf(terminator);
//          qDebug() << line.left(pos);
//          this->addToLogs(line.left(pos));
//    }
//}

//if(secondConnectionWindow){
//        ui->main_text->append("New connection in progress..");
//        if(secondConnectionWindow->deviceSetUp == true){
//            ui->main_text->append("Connected");
//        }else if(secondConnectionWindow->deviceSetUp == false){
//            ui->main_text->append("Not Connected");
//        }

//}

void MainWindow::on_actionConnect_triggered()
{
    QMessageBox::information(this,"title","New Information");
}


void MainWindow::on_test_button_clicked()
{
    secondConnectionWindow->device->setPortName(secondConnectionWindow->give_device_name());
    secondConnectionWindow->device->open(QSerialPort::ReadOnly);
    secondConnectionWindow->device->setBaudRate(QSerialPort::Baud115200);
    secondConnectionWindow->device->setDataBits(QSerialPort::Data8);
    secondConnectionWindow->device->setParity(QSerialPort::NoParity);
    secondConnectionWindow->device->setStopBits(QSerialPort::OneStop);
    secondConnectionWindow->device->setFlowControl(QSerialPort::NoFlowControl);
    connect(secondConnectionWindow->device, SIGNAL(readyRead()) , this, SLOT(secondConnectionWindow->readFromPort()));

    if(secondConnectionWindow->device->canReadLine()){
        QString data = secondConnectionWindow->readFromPort();
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
        ui->main_text->append(currentDateTime + "\t" + data);
    }else{
        ui->main_text->append("Could not read data.");
        return;
    }
}
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
