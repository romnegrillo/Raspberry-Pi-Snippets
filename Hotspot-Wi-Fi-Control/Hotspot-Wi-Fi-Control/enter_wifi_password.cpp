#include "enter_wifi_password.h"
#include "ui_enter_wifi_password.h"


enter_wifi_password::enter_wifi_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter_wifi_password)
{
    ui->setupUi(this);
}

enter_wifi_password::~enter_wifi_password()
{
    delete ui;
}
