#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// For connection window
#include "connectdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Powoduje zamknięcie aplikacji poprzez odpowiednie wywołanie sygnału -> close()
    void on_exit_button_clicked();
    void on_exit_button_pressed();

    // Test button
    void myCustomSlot();

    int on_connectButton_clicked();

    void get_device_name();


private:
    Ui::MainWindow *ui;
    // Drugie okno do obsługi komunikacji
    ConnectDialog *secondConnectionWindow;
};
#endif // MAINWINDOW_H
