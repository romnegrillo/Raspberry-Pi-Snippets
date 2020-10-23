#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
     int current_value;

private slots:



    void on_horizontalSlider_valueChanged(int value);
    void show_wifi_info();
    void show_hotspot_info();





private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H