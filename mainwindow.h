#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// For connection window
#include "connectdialog.h"
<<<<<<< HEAD
#include "device.h"
#include <QSerialPort>

// do obsługi obrazków
#include <QPixmap>

// do obsługi wykresów
#include "QtCharts/QXYSeries"
#include "QtCharts/QLineSeries"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QLogValueAxis>
#include <QValueAxis>

// do obsługi czasu pobieranego do wykresów
#include <QDateTime>

// do obsługi czasu mijającego
#include <QElapsedTimer>

#include "qcustomplot.h"
=======


>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort *device;
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    QtCharts::QChart *chart = new QtCharts::QChart();
    QGridLayout *gridLayout;
    float temp;
    float hum;
    float lux;
=======
    ConnectDialog *secondConnectionWindow;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

private slots:
    // Powoduje zamknięcie aplikacji poprzez odpowiednie wywołanie sygnału -> close()
    void on_exit_button_clicked();
<<<<<<< HEAD

    // Test button
    void myCustomSlot();

    int on_connectButton_clicked();

    void get_device_name();
    // Pobieranie nazwy urządzenia i dane przesyłane

    void on_getdata_clicked();

    void readFromPort();

    void readTemp();

    void insert_image();

    void setup_plants();

    void push_data_to_series(float tempx, QElapsedTimer timer);

    //otwarcie drugiego okna
//    void openNewWindow();


    void createChart();
private:
    Ui::MainWindow *ui;
    // Drugie okno do obsługi komunikacji
    ConnectDialog *secondConnectionWindow;

=======
    void on_exit_button_pressed();

    // Test button

    void on_connectButton_clicked();



    void on_actionConnect_triggered();

    void on_test_button_clicked();

private:
    Ui::MainWindow *ui;
    // Drugie okno do obsługi komunikacji
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
};
#endif // MAINWINDOW_H
