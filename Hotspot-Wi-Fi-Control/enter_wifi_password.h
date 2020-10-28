#ifndef ENTER_WIFI_PASSWORD_H
#define ENTER_WIFI_PASSWORD_H

#include <QDialog>

namespace Ui {
class enter_wifi_password;
}

class enter_wifi_password : public QDialog
{
    Q_OBJECT

public:
    explicit enter_wifi_password(QWidget *parent = 0, QString selected_SSID = 0);
    ~enter_wifi_password();

    QString entered_password;
    void show_keyboard_group(QString group);
    void saveToApSetup(QString ssid, QString passphrase);
    QString getWifSetupValue(QString param);
    void load_button_event();


private slots:
    void on_abc_button_clicked();

    void on_ABC_button_clicked();

    void on_number_button_clicked();

    void on_symbol_button_clicked();

    void on_space_button_clicked();

    void on_del_button_clicked();

    void on_ok_button_clicked();

    void on_cancel_button_clicked();

      void keyboard_clicked(); // Manually added.

private:
    Ui::enter_wifi_password *ui;
};

#endif // ENTER_WIFI_PASSWORD_H
