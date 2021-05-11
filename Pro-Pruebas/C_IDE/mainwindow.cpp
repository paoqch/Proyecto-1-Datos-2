#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "logger.h"
#include <string>
#include <fstream>
#include "QJsonObject"
#include "QJsonDocument"
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include "stringparse.h"
using namespace std;

logger *l1 = new logger();
bool stop_stop = false; //Variable para detener la lectura de code_edit

/**
 * @brief MainWindow::MainWindow
 * Interfaz que permite escribir codigo
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowTitle("C! - IDE");
    ui->Application_Log->setDocumentTitle("Output");
    ui->Application_Log->setReadOnly(true);

}

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * @brief MainWindow::on_RunButton_clicked
 * Ejecuta el codigo
 */
void MainWindow::on_RunButton_clicked(){

    if(!this->reserves){

        ui->Application_Log->appendPlainText(l1->logMessage(2,"Debe reservar la memoria primero"));

    }else{

        string codigo = ui->CodeTextArea->toPlainText().toStdString() +'\n';
        convertidor->SplitString(codigo, '\n', linesCode);

        string instruccions = convertidor->EliminarEspacios( linesCode[i]);
        vector<string> line;
        convertidor->SplitString(instruccions, '#', line);

    }





}

/**
 * @brief MainWindow::addStdOutArea
 * @param linea
 * Envia al Stdout la informacion recibida
 */
void MainWindow::addStdOutArea(QString linea){
    ui->Stdout->appendPlainText(linea);
}

/**
 * @brief MainWindow::addOutputArea
 * Log de ejecucion
 */
void MainWindow::addOutputArea(){
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Empezando ejecucion..."));
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Enviando la informacion al servidor..."));
}


/**
 * @brief MainWindow::addReferencia
 * @param fila
 * Añade una cantidad de referencias al RAM Live View
 */
void MainWindow::addRamView(){

    json obj;

    sleep(0.1);

    string recibido = cliente->GetDato();

    ui->Application_Log->appendPlainText(l1->logMessage(0,"Recibiendo sobre la Ram View"));

    obj = json::parse(recibido);

    int size = obj["size"].get<int>();

    ui->RAM_view->clear();

    ui->RAM_view->setHorizontalHeaderLabels(this->l2);


    for (int j = 0; j < size; ++j) {

        ui->RAM_view->insertRow(ui->RAM_view->rowCount());

        string address = obj[to_string(j)]["address"].get<string>();
        string data = obj[to_string(j)]["data"].get<string>();
        string name = obj[to_string(j)]["name"].get<string>();
        string reference  = obj[to_string(j)]["reference"].get<string>();

        QString qAddress = QString::fromStdString(address);
        QString qData = QString::fromStdString(data);
        QString qName = QString::fromStdString(name);
        QString qReference = QString::fromStdString(reference);

        ui->RAM_view->setItem(j, 0, new QTableWidgetItem(qAddress));
        ui->RAM_view->setItem(j, 1, new QTableWidgetItem(qData));
        ui->RAM_view->setItem(j, 2, new QTableWidgetItem(qName));
        ui->RAM_view->setItem(j, 3, new QTableWidgetItem(qReference));


    }

}

/**
 * @brief MainWindow::on_pushButton_clicked
 * Metodo para reiniciar la ejecucion
 */
void MainWindow::on_pushButton_clicked(){
    reiniciarParseo();
}

/**
 * @brief MainWindow::on_stop_clicked
 * Metodo para detener la ejecucion
 */
void MainWindow::on_stop_clicked(){
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se detuvo la ejecucion"));
    i = 0;
    linesCode.clear();
    ui->editLine->clear();
    cliente->StartClient(convertidor->Reseteo());
}

/**
 * @brief MainWindow::on_clear_clicked
 * Metodo para limpiar el app log
 */
void MainWindow::on_clear_clicked(){
    ui->Application_Log->clear();
    ui->Stdout->clear();
    ui->editLine->clear();
    ui->RAM_view->clear();
    ui->RAM_view->setHorizontalHeaderLabels(this->l2);
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Eliminar información del log"));
}

/**
 * @brief MainWindow::reiniciarParseo
 * Reinicia el puntero del parser
 */
void MainWindow::reiniciarParseo(){
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se reinicio el sistema..."));
    ui->CodeTextArea->clear();
    i = 0;
    linesCode.clear();
    ui->RAM_view->clear();
    cliente->StartClient(convertidor->Reseteo());
}

/**
 * @brief MainWindow::on_Next_clicked
 */
void MainWindow::on_Next_clicked(){

    if (i < linesCode.size()-1){

        string instruccions = convertidor->EliminarEspacios( linesCode[i]);
        vector<string> line;
        bool condicion = convertidor->structCommand;

        convertidor->SplitString(instruccions, '#', line);

        string valorEnviar;

        if(line[0] == "int" && !condicion){

            valorEnviar = convertidor->GenerarInt(line);

        }else if (line[0] == "char" && !condicion){

            valorEnviar = convertidor->GenerarChar(line);

        }else if (line[0] == "long" && !condicion){

            valorEnviar = convertidor->GenerarLong(line);

        }else if (line[0] == "double" && !condicion){

            valorEnviar = convertidor->GenerarDouble(line);

        }else if (line[0] == "float" && !condicion){

            valorEnviar = convertidor->GenerarFloat(line);

        }else if (line[0] == "{" && !condicion){

            valorEnviar = convertidor->GenerarInicio();

        }else if(line[0] == "}" && condicion){

            convertidor->structCommand = false;
            valorEnviar = convertidor->GenerarStruct(line);

        }else if(line[0] == "}" && !condicion){

            valorEnviar = convertidor->GenerarFinal();

        }else if(condicion){

            convertidor->linesStruct.push_back(instruccions);
            valorEnviar = "vacio";

        }else if(line[0] == "struct"){

            convertidor->structCommand = true;
            valorEnviar = "vacio";

        }else if (line[0] == "reference" && !condicion){

            valorEnviar = convertidor->GenerarReference(line);

        }else if (line[0] == "") {

            valorEnviar = "vacio";

        }

        if(convertidor->flag){
            ui->Application_Log->appendPlainText(l1->logMessage(0,"Pidiendo dato"));
            ui->Application_Log->appendPlainText(l1->logMessage(0,"Recibiendo dato"));
            convertidor->flag = false;
        }

        if(valorEnviar == "error"){
            ui->Application_Log->appendPlainText(l1->logMessage(2,"Error de sintaxis"));
            on_stop_clicked();
        } else if(valorEnviar == "ErrorDato"){
            ui->Application_Log->appendPlainText(l1->logMessage(2,"El dato no existe"));
            on_stop_clicked();
        } else if (valorEnviar == "vacio"){
            line.clear();
            i++;
            ui->editLine->clear();
            ui->editLine->appendPlainText(QString::number(i));
        } else if(line[0] == "cout"){
            valorEnviar = convertidor->GenerarCout(line);
            ui->Stdout->appendPlainText(QString::fromStdString(valorEnviar));
            i++;
        } else {
            cliente->StartClient(valorEnviar);
            ui->Application_Log->appendPlainText(l1->logMessage(0,"Enviando información"));
            line.clear();
            i++;
            ui->editLine->clear();
            ui->editLine->appendPlainText(QString::number(i));
            addRamView();
        }

        if(i%100 == 0){
            valorEnviar = convertidor->GarbageCollector();
            cliente->StartClient(valorEnviar);
            ui->Application_Log->appendPlainText(l1->logMessage(0,"Se realizó el garbage collector"));
        }

    } else{
        ui->Application_Log->appendPlainText(l1->logMessage(1,"No hay ejeccución en proceso"));
        on_stop_clicked();
    }
}

void MainWindow::on_reverseButton_clicked()
{
    string memoria = ui->editReserve->toPlainText().toStdString();
    string memoriaEnviar = convertidor->Reserve(memoria);
    ui->Application_Log->appendPlainText(l1->logMessage(0,"Reservando memoria"));
    cliente->StartClient(memoriaEnviar);
    this->reserves = true;
}
