/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *RunButton;
    QPlainTextEdit *CodeTextArea;
    QTableWidget *RAM_view;
    QLabel *label;
    QPlainTextEdit *Stdout;
    QPlainTextEdit *Application_Log;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *clear;
    QPushButton *stop;
    QLabel *label_4;
    QLabel *label_Analyzed_Line;
    QPushButton *pushButton;
    QPushButton *Next;
    QPlainTextEdit *editLine;
    QPlainTextEdit *editReserve;
    QLabel *label_5;
    QPushButton *reverseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(980, 611);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        RunButton = new QPushButton(centralwidget);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(20, 10, 89, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/C--master (1)/C--master/Cliente/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        RunButton->setIcon(icon);
        CodeTextArea = new QPlainTextEdit(centralwidget);
        CodeTextArea->setObjectName(QString::fromUtf8("CodeTextArea"));
        CodeTextArea->setGeometry(QRect(20, 50, 531, 251));
        CodeTextArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        RAM_view = new QTableWidget(centralwidget);
        if (RAM_view->columnCount() < 4)
            RAM_view->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        RAM_view->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        RAM_view->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        RAM_view->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        RAM_view->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        RAM_view->setObjectName(QString::fromUtf8("RAM_view"));
        RAM_view->setGeometry(QRect(570, 50, 401, 441));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 20, 111, 17));
        Stdout = new QPlainTextEdit(centralwidget);
        Stdout->setObjectName(QString::fromUtf8("Stdout"));
        Stdout->setGeometry(QRect(20, 330, 531, 81));
        Stdout->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Application_Log = new QPlainTextEdit(centralwidget);
        Application_Log->setObjectName(QString::fromUtf8("Application_Log"));
        Application_Log->setGeometry(QRect(20, 450, 531, 111));
        Application_Log->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 310, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 430, 121, 17));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(468, 420, 81, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Downloads/C--master (1)/C--master/Cliente/trash.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        clear->setIcon(icon1);
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(120, 10, 89, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Downloads/st.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 520, 101, 17));
        label_Analyzed_Line = new QLabel(centralwidget);
        label_Analyzed_Line->setObjectName(QString::fromUtf8("label_Analyzed_Line"));
        label_Analyzed_Line->setGeometry(QRect(680, 330, 67, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 89, 25));
        Next = new QPushButton(centralwidget);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(320, 10, 89, 25));
        editLine = new QPlainTextEdit(centralwidget);
        editLine->setObjectName(QString::fromUtf8("editLine"));
        editLine->setGeometry(QRect(670, 510, 41, 31));
        editReserve = new QPlainTextEdit(centralwidget);
        editReserve->setObjectName(QString::fromUtf8("editReserve"));
        editReserve->setGeometry(QRect(740, 510, 91, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(840, 520, 67, 17));
        reverseButton = new QPushButton(centralwidget);
        reverseButton->setObjectName(QString::fromUtf8("reverseButton"));
        reverseButton->setGeometry(QRect(870, 510, 89, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 980, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        RunButton->setText(QApplication::translate("MainWindow", "  Run", nullptr));
        QTableWidgetItem *___qtablewidgetitem = RAM_view->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Direccion", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = RAM_view->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Valor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = RAM_view->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Etiqueta", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = RAM_view->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Referencias", nullptr));
        label->setText(QApplication::translate("MainWindow", "RAM Live View", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Stdout", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Application Log", nullptr));
        clear->setText(QApplication::translate("MainWindow", "  Clear", nullptr));
        stop->setText(QApplication::translate("MainWindow", "  Stop", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Analyzed Line:", nullptr));
        label_Analyzed_Line->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        Next->setText(QApplication::translate("MainWindow", "Next", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "MB", nullptr));
        reverseButton->setText(QApplication::translate("MainWindow", "Reserve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
