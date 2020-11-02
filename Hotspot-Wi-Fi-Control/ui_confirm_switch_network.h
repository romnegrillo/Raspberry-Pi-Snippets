/********************************************************************************
** Form generated from reading UI file 'confirm_switch_network.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_SWITCH_NETWORK_H
#define UI_CONFIRM_SWITCH_NETWORK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_confirm_switch_network
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *message_label;
    QLabel *label;

    void setupUi(QDialog *confirm_switch_network)
    {
        if (confirm_switch_network->objectName().isEmpty())
            confirm_switch_network->setObjectName(QString::fromUtf8("confirm_switch_network"));
        confirm_switch_network->resize(800, 480);
        buttonBox = new QDialogButtonBox(confirm_switch_network);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 350, 671, 51));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        message_label = new QLabel(confirm_switch_network);
        message_label->setObjectName(QString::fromUtf8("message_label"));
        message_label->setGeometry(QRect(160, 70, 531, 211));
        message_label->setAlignment(Qt::AlignCenter);
        label = new QLabel(confirm_switch_network);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 20, 67, 17));

        retranslateUi(confirm_switch_network);
        QObject::connect(buttonBox, SIGNAL(accepted()), confirm_switch_network, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), confirm_switch_network, SLOT(reject()));

        QMetaObject::connectSlotsByName(confirm_switch_network);
    } // setupUi

    void retranslateUi(QDialog *confirm_switch_network)
    {
        confirm_switch_network->setWindowTitle(QApplication::translate("confirm_switch_network", "Dialog", 0, QApplication::UnicodeUTF8));
        message_label->setText(QApplication::translate("confirm_switch_network", "-", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("confirm_switch_network", "Continue?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class confirm_switch_network: public Ui_confirm_switch_network {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_SWITCH_NETWORK_H
