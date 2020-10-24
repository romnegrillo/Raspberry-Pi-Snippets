#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>
#include <QDialog>
#include "confirm_switch_network.h"
#include <QNetworkConfigurationManager>
#include <QTimer>
#include <QNetworkAccessManager>

int previous_clicked = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int next_value)
{
    // this->current_value is read from the constructor in the config file.

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
                qDebug() << "Called";
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
                qDebug() << "Called";
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

    ui->wifi_list->clear();

    QNetworkConfigurationManager nwkMgr;

    nwkMgr.updateConfigurations();


    // UPDATE this code needs to run in the slot for QNetworkManager::updateCompleted signal
    QList<QNetworkConfiguration> nwkCnfList = nwkMgr.allConfigurations();

    for(int i=0; i<nwkCnfList.length(); i++)
    {
        if (nwkCnfList[i].bearerType() == QNetworkConfiguration::BearerWLAN)
        {

            ui->wifi_list->addItem(QString::fromUtf8(" ✓ ") +  nwkCnfList[i].name());

        }
    }
}


void MainWindow::show_hotspot_info()
{
    ui->wif_list_groupbox->setVisible(false);
}

void MainWindow::update_wifi_list()
{
    this->show_wifi_info();
}





