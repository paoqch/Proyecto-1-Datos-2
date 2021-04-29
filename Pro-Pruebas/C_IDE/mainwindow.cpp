#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "logger.h"
#include <string>
#include <fstream>
#include "client.h"
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
    createClient();
}

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * @brief MainWindow::on_RunButton_clicked
 * Ejecuta el codigo
 */
void MainWindow::on_RunButton_clicked(){
    string codigo = ui->CodeTextArea->toPlainText().toStdString() +'\n';
    convertidor->SplitString(codigo, '\n', linesCode);

    string instruccions = convertidor->EliminarEspacios( linesCode[i]);
    vector<string> line;
    convertidor->SplitString(instruccions, '#', line);


    QJsonObject objeto = parser.parse(line);
    QJsonDocument doc(objeto);
    QByteArray bytes = doc.toJson();
    const char* charString = bytes.data();
    string someString(charString);
    sendData(someString);

    if(cliente->jsonActual.isEmpty()){
        ui->RAM_view->rowCount();
    }else {
        //ui->RunButton->click();
        //addOutputArea();
        ui->RAM_view->insertRow(ui->RAM_view->rowCount());
        int fila = ui->RAM_view->rowCount() -1;

        addMemoryDirection(fila,cliente->jsonActual.value("Address").toString());
        addValor(fila,cliente->jsonActual.value("Value").toString());
        addEtiqueta(fila,cliente->jsonActual.value("Label").toString());
        addReferencia(fila);

        QString linea = QString("");
        addOutputArea();
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
 * @brief MainWindow::addMemoryDirection
 * @param fila
 * @param address
 * Añade una direccion de memoria address al RAM Live View
 */
void MainWindow::addMemoryDirection(int fila, QString address){
    ui->RAM_view->setItem(fila,Direccion,new QTableWidgetItem(address));
}

/**
 * @brief MainWindow::addValor
 * @param fila
 * @param value
 * Añade un valor value al RAM Live View
 */
void MainWindow::addValor(int fila,QString value){
    ui->RAM_view->setItem(fila,Valor,new QTableWidgetItem(value));
}

/**
 * @brief MainWindow::addEtiqueta
 * @param fila
 * @param label
 * Añade una etiqueta label al RAM Live View
 */
void MainWindow::addEtiqueta(int fila,QString label){
    ui->RAM_view->setItem(fila, Etiqueta,new QTableWidgetItem(label));
}

/**
 * @brief MainWindow::addReferencia
 * @param fila
 * Añade una cantidad de referencias al RAM Live View
 */
void MainWindow::addReferencia(int fila){
    ui->RAM_view->setItem(fila,Referencias,new QTableWidgetItem("1"));
}

//Instancia la clase Client
void MainWindow::createClient(){
    Client* client = new Client(0,"127.0.0.1",8888);
    cliente = client;
     ui->Application_Log->appendPlainText(l1->logMessage(0,"Estableciendo conexion con el servidor..."));
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
    stop_stop = false;
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se detuvo la ejecucion"));
}

/**
 * @brief MainWindow::sendData
 * @param data
 * Envia una data en JSON al servidor
 */
void MainWindow::sendData(string data){
    cliente->SendData(QString(data.c_str()));
}

/**
 * @brief MainWindow::on_clear_clicked
 * Metodo para limpiar el app log
 */
void MainWindow::on_clear_clicked(){
    ui->Application_Log->clear();
}

/**
 * @brief MainWindow::reiniciarParseo
 * Reinicia el puntero del parser
 */
void MainWindow::reiniciarParseo(){
    ui->Application_Log->appendPlainText(l1->logMessage(1,"Se reinicio el sistema..."));
}

/**
 * @brief MainWindow::on_Next_clicked
 */
void MainWindow::on_Next_clicked(){
    if (i < linesCode.size()){
        string instruccions = convertidor->EliminarEspacios( linesCode[i]);
        vector<string> line;

        convertidor->SplitString(instruccions, '#', line);

        string valorEnviar;

        if(line[0] == "int"){

            valorEnviar = convertidor->GenerarInt(line);
            cout << valorEnviar;

        }else if (line[0] == "char"){

            valorEnviar = convertidor->GenerarChar(line);
            cout << valorEnviar;

        }else if (line[0] == "long"){

            valorEnviar = convertidor->GenerarLong(line);
            cout << valorEnviar;

        }else if (line[0] == "double"){

            valorEnviar = convertidor->GenerarDouble(line);
            cout << valorEnviar;

        }else if (line[0] == "float"){

            valorEnviar = convertidor->GenerarFloat(line);
            cout << valorEnviar;

        }else if (line[0] == "{"){

            valorEnviar = "Generate";

        }else if(line[0] == "}"){

            valorEnviar = "Eliminar";

        }else if (line[0] == "reference"){

            valorEnviar = convertidor->GenerarReference(line);
            cout << valorEnviar;

        }else if(line[0] == "cout"){

            valorEnviar = convertidor->GenerarCout(line);

        }

        if(valorEnviar == "error"){
            //EJECUTAR ERROR
        }

        cout << valorEnviar;
        line.clear();
        i++;


    }
}
