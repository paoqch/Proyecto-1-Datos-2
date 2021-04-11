#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>
#else
#include <QtGui/QMainWindow>
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void leer_socketservidor();

private slots:
    void on_run_clicked();
    void on_stop_clicked();
    void on_clear_clicked();


private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpmainwindow; /**< TODO: describe */
};

#endif // MAINWINDOW_H
