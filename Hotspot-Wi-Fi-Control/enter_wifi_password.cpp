#include "enter_wifi_password.h"
#include "ui_enter_wifi_password.h"


enter_wifi_password::enter_wifi_password(QWidget *parent, QString selected_SSID) :
    QDialog(parent),
    ui(new Ui::enter_wifi_password)
{
    ui->setupUi(this);
    this->entered_password = "";
    ui->ssid_textbox->setText(selected_SSID);
    this->show_keyboard_group("abc");

}

enter_wifi_password::~enter_wifi_password()
{
    delete ui;
}



void enter_wifi_password::on_abc_button_clicked()
{
    this->show_keyboard_group("abc");
}

void enter_wifi_password::on_ABC_button_clicked()
{
    this->show_keyboard_group("ABC");
}

void enter_wifi_password::on_number_button_clicked()
{
    this->show_keyboard_group("123");
}

void enter_wifi_password::on_symbol_button_clicked()
{
    this->show_keyboard_group("#+=");
}

void enter_wifi_password::on_space_button_clicked()
{

}

void enter_wifi_password::on_del_button_clicked()
{

}

void enter_wifi_password::show_keyboard_group(QString group)
{
    if(group == "abc")
    {
        ui->abc_groupbox->show();
        ui->ABC_groupbox->hide();
        ui->number_groupbox->hide();
        ui->symbol_groupbox->hide();
    }
    else if(group == "ABC")
    {
        ui->abc_groupbox->hide();
        ui->ABC_groupbox->show();
        ui->number_groupbox->hide();
        ui->symbol_groupbox->hide();
    }
    else if(group == "123")
    {
        ui->abc_groupbox->hide();
        ui->ABC_groupbox->hide();
        ui->number_groupbox->show();
        ui->symbol_groupbox->hide();
    }
    else if(group == "#+=")
    {
        ui->abc_groupbox->hide();
        ui->ABC_groupbox->hide();
        ui->number_groupbox->hide();
        ui->symbol_groupbox->show();
    }
}

void enter_wifi_password::on_ok_button_clicked()
{

}

void enter_wifi_password::on_cancel_button_clicked()
{
    this->close();
}
