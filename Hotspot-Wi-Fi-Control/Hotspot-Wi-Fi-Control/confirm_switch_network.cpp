#include "confirm_switch_network.h"
#include "ui_confirm_switch_network.h"

confirm_switch_network::confirm_switch_network(QWidget *parent, int current_value) :
    QDialog(parent),
    ui(new Ui::confirm_switch_network)
{
    ui->setupUi(this);

    // Switching from wifi mode to hotspot mode.
    if(current_value == 0)
    {
        QString message;
        message += "You are currently in Wi-Fi Mode, switching\n";
        message += "to Hotspot Mode requires to reboot the printer.";

        ui->message_label->setText(message);
    }
    // Switching from hotspot mode to wifi mode.
    else if(current_value == 1)
    {
        QString message;
        message += "You are currently in Hotspot Mode, switching\n";
        message += "to Wi-Fi Mode requires to reboot the printer.\n\n";
        message += "You can select a network on next boot.";

        ui->message_label->setText(message);
    }
}

confirm_switch_network::~confirm_switch_network()
{
    delete ui;
}
