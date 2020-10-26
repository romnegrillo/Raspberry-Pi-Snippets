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
    explicit enter_wifi_password(QWidget *parent = 0);
    ~enter_wifi_password();

private:
    Ui::enter_wifi_password *ui;
};

#endif // ENTER_WIFI_PASSWORD_H
