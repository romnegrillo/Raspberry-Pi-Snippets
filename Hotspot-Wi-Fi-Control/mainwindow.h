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

    void load_settings();
    void saveToApSetup(QString ssid, QString passphrase);
    QString getApSetupValue(QString param);

private:
     int current_value;

private slots:



    void on_horizontalSlider_valueChanged(int value);
    void show_wifi_info();
    void show_hotspot_info();
    void update_wifi_list();
    void connect_selected_wifi();



    void on_connect_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
