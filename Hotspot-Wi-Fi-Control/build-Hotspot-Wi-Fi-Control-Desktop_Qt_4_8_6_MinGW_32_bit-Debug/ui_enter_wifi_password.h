/********************************************************************************
** Form generated from reading UI file 'enter_wifi_password.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTER_WIFI_PASSWORD_H
#define UI_ENTER_WIFI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_enter_wifi_password
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *enter_wifi_password)
    {
        if (enter_wifi_password->objectName().isEmpty())
            enter_wifi_password->setObjectName(QString::fromUtf8("enter_wifi_password"));
        enter_wifi_password->resize(686, 438);
        buttonBox = new QDialogButtonBox(enter_wifi_password);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 370, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(enter_wifi_password);
        QObject::connect(buttonBox, SIGNAL(accepted()), enter_wifi_password, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), enter_wifi_password, SLOT(reject()));

        QMetaObject::connectSlotsByName(enter_wifi_password);
    } // setupUi

    void retranslateUi(QDialog *enter_wifi_password)
    {
        enter_wifi_password->setWindowTitle(QApplication::translate("enter_wifi_password", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class enter_wifi_password: public Ui_enter_wifi_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTER_WIFI_PASSWORD_H
