/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *wif_list_groupbox;
    QListWidget *wifi_list;
    QPushButton *connect_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(330, 0, 121, 71));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { \n"
"	background-color: #AAAAAA;\n"
"	height: 40%; \n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal { \n"
"	background-color: green; \n"
"	width: 60%; \n"
"	height: 50%;\n"
"	border-radius: 20px; \n"
"}\n"
""));
        horizontalSlider->setMaximum(1);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setTracking(false);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 30, 111, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 30, 111, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 70, 101, 41));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 70, 121, 41));
        wif_list_groupbox = new QGroupBox(centralWidget);
        wif_list_groupbox->setObjectName(QString::fromUtf8("wif_list_groupbox"));
        wif_list_groupbox->setGeometry(QRect(40, 110, 721, 311));
        wifi_list = new QListWidget(wif_list_groupbox);
        wifi_list->setObjectName(QString::fromUtf8("wifi_list"));
        wifi_list->setGeometry(QRect(10, 20, 701, 221));
        connect_button = new QPushButton(wif_list_groupbox);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setGeometry(QRect(610, 260, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Wi-Fi Mode", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Hotspot Mode", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "IP Address:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "192.168.4.1", 0, QApplication::UnicodeUTF8));
        wif_list_groupbox->setTitle(QApplication::translate("MainWindow", "Wi-Fi Networks", 0, QApplication::UnicodeUTF8));
        connect_button->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
