#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QThread>

logger *l1 = new logger();
QThread workerThread; /**< Hilo/Thread */
bool stop_stop = false; /**< Variable para detener la lectura de code_edit */
QStringList linesGo_on; /**< Lista de las lineas del code_edit */
int indGO_ON =0; /**< Cantidad de lineas en el code_edit */
int row_ind = 0;  /** < Fila de la tabla  */

//variables referenciadas
enum colu{
    Mem_Adr ,Val , Tag , Ref
  //  0       1     2     3
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("C! - IDE");
    tcpmainwindow = new QTcpSocket(this);
    tcpmainwindow->connectToHost(QHostAddress::LocalHost,8888);
    connect(tcpmainwindow, SIGNAL(readyRead()),this,SLOT(leer_socketservidor()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_run_clicked()
{
        QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
        QStringList lines = plainTextEditContents.split("\n");
        int sizeLines = lines.length();
        ui->Application_Log->insertPlainText(l1->logMessage(0,"Starting Execute..."));

        int ind = 0;

        while ( ind < sizeLines){
            workerThread.msleep(1000);
            ind++;
        }
}


void MainWindow::on_stop_clicked()
{
    stop_stop = false;
}

void MainWindow::on_clear_clicked()
{
    ui->Application_Log->clear();
}

