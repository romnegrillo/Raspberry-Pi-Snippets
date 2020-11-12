#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>
#include <QDialog>
#include "confirm_switch_network.h"
#include <QNetworkConfigurationManager>
#include <QTimer>
#include "enter_wifi_password.h"
#include <QFile>
#include <QTextStream>

int previous_clicked = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_settings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_settings()
{
    // This should be read in config file.
    this->current_value = 0; // sample

    if(this->current_value == 0)
    {
        this->show_wifi_info();

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update_wifi_list()));
        timer->start(5000);
    }
    else
    {
        this->show_hotspot_info();
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int next_value)
{
    // this->current_value is read from the constructor in the config file.
    // at the constructor.

    // Transition from wifi mode to hotspot mode.
    if(this->current_value == 0 && next_value == 1)
    {
        if(!previous_clicked)
        {
            confirm_switch_network* confirm_switch_network_obj = new confirm_switch_network(0, this->current_value);
            confirm_switch_network_obj->setModal(true);

            if (confirm_switch_network_obj->exec())
            {
                this->current_value = next_value;
            }
            else
            {
                previous_clicked = true;
            }
        }
        else
        {
            previous_clicked = false;
        }
    }

    // Transition from hotspot mode to wifi mode.
    else if(this->current_value == 1 && next_value == 0)
    {
        if(!previous_clicked)
        {
            confirm_switch_network* confirm_switch_network_obj = new confirm_switch_network(0, this->current_value);
            confirm_switch_network_obj->setModal(true);

            if (confirm_switch_network_obj->exec())
            {
                this->current_value = next_value;

            }
            else
            {
                previous_clicked = true;
            }
        }
        else
        {
            previous_clicked = false;
        }
    }

    ui->horizontalSlider->setValue(this->current_value);

    if(this->current_value == 0)
    {
        this->show_wifi_info();
    }
    else
    {
        this->show_hotspot_info();
    }

}

void MainWindow::show_wifi_info()
{
    ui->wif_list_groupbox->setVisible(true);
    ui->hotspot_info_groupbox->setVisible(false);
    ui->wifi_list->clear();

    QNetworkConfigurationManager nwkMgr;

    nwkMgr.updateConfigurations();

    QList<QNetworkConfiguration> nwkCnfList = nwkMgr.allConfigurations();

    for(int i=0; i<nwkCnfList.length(); i++)
    {
        if (nwkCnfList[i].bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            ui->wifi_list->addItem(nwkCnfList[i].name());
        }
    }
}


void MainWindow::show_hotspot_info()
{
    ui->wif_list_groupbox->setVisible(false);
    ui->hotspot_info_groupbox->setVisible(true);
}

void MainWindow::update_wifi_list()
{
    if(this->current_value == 0)
    {
        this->show_wifi_info();
    }
}

void MainWindow::connect_selected_wifi()
{
    QListWidgetItem* selected_SSID_item =  ui->wifi_list->currentItem();

    if(selected_SSID_item == NULL)
    {
        return;
    }

    QString selected_SSID = selected_SSID_item->text();

    // Open new window to enter password.
    enter_wifi_password* enter_wifi_password_obj = new enter_wifi_password(0, selected_SSID);
    enter_wifi_password_obj->exec();
}


void MainWindow::on_connect_button_clicked()
{
    this->connect_selected_wifi();
}

void MainWindow::saveToApSetup(QString ssid, QString passphrase)
{
    /*
     This function accepts ssid and password for the hotspot
     and replaces the current ssid and password.

     A reboot is required for it to take effect as of the moment.
    */

    QFile file("scripts/apsetup.sh");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    { //you can send a message or throw error signal here
        return;
    }
    QTextStream in(&file);
    QString strLine = QString("");
    QStringList line;
    while (!in.atEnd())
    {
        int startPos1 = 0;
        int startPos2 = 0;
        strLine = in.readLine();
        startPos1 = strLine.indexOf("ssid=", 0, Qt::CaseInsensitive);
        if (startPos1 >= 0)
        {
            line.append("ssid=" + ssid);
        }
        startPos2 = strLine.indexOf("wpa_passphrase=", 0, Qt::CaseInsensitive);
        if (startPos2 >= 0)
        {
            line.append("wpa_passphrase=" + passphrase);
        }
        if ((startPos1 < 0) && (startPos2 < 0))
        {
            line.append(strLine);
        }
    }
    file.close();
    QFile fileOut("scripts/apsetup_temp.sh");
    if (fileOut.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream s(&fileOut);
        for (int i = 0; i < line.size(); ++i)
          s << line.at(i) << '\n';
    }
    fileOut.close();
}

QString MainWindow::getApSetupValue(QString param)
{
    /*
     This function accepts a key that will be read
     inside the apsetup.sh and returns the value of that key.

     Example:
        QString strSSID = getApSetupValue("SSID");
        QString strPassPhrase = getApSetupValue("Passphrase");

     A reboot is required for it to take effect as of the moment.
    */

    QString retValue = "";
    QFile file("scripts/apsetup.sh");
    QString line = QString("");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return QString("");
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line = in.readLine();
        int startPos = 0;
        if (param == "SSID")
        {
            startPos = line.indexOf("ssid=", 0, Qt::CaseInsensitive);
            if (startPos >= 0)
            {
                retValue = line.mid(startPos+5);
            }
        }
        else
        {
            startPos = line.indexOf("wpa_passphrase=", 0, Qt::CaseInsensitive);
            if (startPos >= 0)
            {
                retValue = line.mid(startPos+15);
            }
        }
        if (retValue != QString(""))
            break;
    }
    file.close();
    return retValue;
}
