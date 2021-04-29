#include "variables.h"
#include <QDebug>
#include <QJsonDocument>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;
/**
 * @brief variables::variables
 * Clase encargada de procesar las solicitudes del cliente
 */
variables::variables(){
}
/**
 * @brief variables::preparation
 * @param object
 * @return
 * Analiza los parámetros del objeto JSON object
 */
QString variables::preparation(QJsonObject object){
        QString type = QString(object.value("Type").toString());
        QString label = QString(object.value("Variable").toString());
        QString valor;
        if (type == QString("int")){
            string analisis = analizarValor(object.value("Value").toString().toUtf8().constData(), type.toUtf8().constData());
            int value;
            value = atoi(analisis.c_str());
            qDebug()<<"Nodo insertado...";
            valor = QString::fromStdString(to_string(value).c_str());
            cout<<"Valor preparation " + value;


        }else if (type == QString("double")){
            string analisis = analizarValor(object.value("Value").toString().toUtf8().constData(), type.toUtf8().constData());
            double value;
            string S = analisis;
            istringstream(S) >> value;
            qDebug()<<"Nodo insertado...";
            valor = QString::fromStdString(to_string(value).c_str());
        }
        else{
            qDebug()<<"No se encuentra el tipo"<<endl;
        }
        return valor;
}

/**
 * @brief variables::analizarValor
 * @param valor
 * @param tipo
 * @return
 * Analiza si valor cumple con la definición de tipo
 */
string variables::analizarValor(string valor, string tipo){

    if (tipo == "int"){
        return valor;
        cout<<"Valor analizar "+valor;
    }

    else if (tipo == "double"){
        return valor;
    }

    else if (tipo == "float"){
        return valor;
    }

    else if (tipo == "long"){
        return valor;
    }

}
