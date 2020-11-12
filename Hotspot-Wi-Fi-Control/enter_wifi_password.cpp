#include "enter_wifi_password.h"
#include "ui_enter_wifi_password.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

enter_wifi_password::enter_wifi_password(QWidget *parent, QString selected_SSID) :
    QDialog(parent),
    ui(new Ui::enter_wifi_password)
{
    ui->setupUi(this);
    this->entered_password = "";
    ui->ssid_textbox->setText(selected_SSID);
    this->show_keyboard_group("abc");
    load_button_event();

}

enter_wifi_password::~enter_wifi_password()
{
    delete ui;
}

void enter_wifi_password::load_button_event()
{
    // Based on their object name (pushButton_n where n is a number), does not matter
    // if it exists or not as long as it covers the all the needed button names.
    int button_count = 140;

    QPushButton *keyboard_buttons[button_count];

    for(int i=0; i<button_count; i++)
    {
        QString button_name = "pushButton_" + QString::number(i);


        if(enter_wifi_password::findChild<QPushButton *>(button_name))
        {
            keyboard_buttons[i] = enter_wifi_password::findChild<QPushButton *>(button_name);
            keyboard_buttons[i]->setStyleSheet("color: rgb(255,0,0);");
            connect(keyboard_buttons[i], SIGNAL(released()), this, SLOT(keyboard_clicked()));
        }


    }
}

void enter_wifi_password::keyboard_clicked()
{
    QPushButton *button =(QPushButton *)sender();
    QString button_text = button->text();

    ui->password_textbox->setText(button_text);

    qDebug() << button_text;
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

void enter_wifi_password::saveToApSetup(QString ssid, QString passphrase)
{
    QFile file("scripts/wifisetup.sh");
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
        startPos1 = strLine.indexOf("ssid=\"", 0, Qt::CaseInsensitive);
        if (startPos1 >= 0)
        {
            line.append("ssid=\"" + ssid+"\"");
        }
        startPos2 = strLine.indexOf("psk=\"", 0, Qt::CaseInsensitive);
        if (startPos2 >= 0)
        {
            line.append("psk=\"" + passphrase+"\"");
        }
        if ((startPos1 < 0) && (startPos2 < 0))
        {
            line.append(strLine);
        }
    }
    file.close();
    QFile fileOut("scripts/wifisetup_temp.sh");
    if (fileOut.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream s(&fileOut);
        for (int i = 0; i < line.size(); ++i)
            s << line.at(i) << '\n';
    }
    fileOut.close();
}

QString enter_wifi_password::getWifSetupValue(QString param)
{
    QString retValue = "";
    QFile file("scripts/wifisetup.sh");
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
        int lastPos = 0;
        if (param == "SSID")
        {
            startPos = line.indexOf("ssid=", 0, Qt::CaseInsensitive);
            lastPos = line.lastIndexOf("\"");
            if (startPos >= 0)
            {
                retValue = line.mid(startPos+6,lastPos-1);
            }
        }
        else
        {
            startPos = line.indexOf("psk=", 0, Qt::CaseInsensitive);
            lastPos = line.lastIndexOf("\"");
            if (startPos >= 0)
            {
                retValue = line.mid(startPos+5, lastPos-1);
            }
        }
        if (retValue != QString(""))
            break;
    }
    file.close();
    return retValue;
}
