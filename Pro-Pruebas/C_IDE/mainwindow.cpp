#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "logger.h"
#include <string>
#include <fstream>
#include "client.h"
#include "QJsonObject"
#include "QJsonDocument"
#include <stdio.h>
#include <unistd.h>
using namespace std;

logger *l1 = new logger();
bool stop_stop = false; //Variable para detener la lectura de code_edit


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowTitle("C! - IDE");
    ui->Application_Log->setDocumentTitle("Output");
    ui->Application_Log->setReadOnly(true);
    createClient();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RunButton_clicked()
{
    string codigo = ui->CodeTextArea->toPlainText().toStdString();
    addOutputArea();
    ui->RAM_view->insertRow(ui->RAM_view->rowCount());
    int fila = ui->RAM_view->rowCount() -1;

    addMemoryDirection(fila,cliente->jsonActual.value("Address").toString());
    addValor(fila,cliente->jsonActual.value("Value").toString());
    addEtiqueta(fila,cliente->jsonActual.value("Label").toString());
    addReferencia(fila);

    QString linea = QString("");
    addOutputArea();
}

//Envia al Stdout la informacion recibida
void MainWindow::addStdOutArea(QString linea){
    ui->Stdout->appendPlainText(linea);
}

//Log de ejecucion
void MainWindow::addOutputArea(){
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Empezando ejecucion..."));
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Enviando la informacion al servidor..."));
}

//Añade una direccion de memoria address al RAM Live View
void MainWindow::addMemoryDirection(int fila, QString address){
    ui->RAM_view->setItem(fila,Direccion,new QTableWidgetItem("address"));
}

// Añade un valor value al RAM Live View
void MainWindow::addValor(int fila,QString value){
    ui->RAM_view->setItem(fila,Valor,new QTableWidgetItem("value"));
}

//Añade una etiqueta label al RAM Live View
void MainWindow::addEtiqueta(int fila,QString label){
    ui->RAM_view->setItem(fila, Etiqueta,new QTableWidgetItem("label"));
}

//Añade una cantidad de referencias al RAM Live View
void MainWindow::addReferencia(int fila){
    ui->RAM_view->setItem(fila,Referencias,new QTableWidgetItem("1"));
}

//Instancia la clase Client
void MainWindow::createClient(){
    Client* client = new Client(0,"127.0.0.1",8888);
    cliente = client;
     ui->Application_Log->appendPlainText(l1->logMessage(0,"Estableciendo conexion con el servidor..."));
}

//Metodo para reiniciar la ejecucion
void MainWindow::on_pushButton_clicked()
{
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se reinicio el sistema..."));
}

//Metodo para detener la ejecucion
void MainWindow::on_stop_clicked()
{
    stop_stop = false;
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se detuvo la ejecucion"));
}

//Metodo para limpiar el app log
void MainWindow::on_clear_clicked()
{
    ui->Application_Log->clear();
}

