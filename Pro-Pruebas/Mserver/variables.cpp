#include "variables.h"
#include <QDebug>
#include <QJsonDocument>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

//

using namespace std;

variables::variables()
{
    mallocPtr = new Malloc(1024);
}

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


string variables::analizarValor(string valor, string tipo){

    ///
    ///Operaciones con enteros
    ///

    if (tipo == "int"){
        return valor;
    }

    if (tipo == "double"){
        return valor;
    }

}
