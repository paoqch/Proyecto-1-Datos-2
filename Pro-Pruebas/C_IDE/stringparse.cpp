#include "stringparse.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h>
#include <iostream>
#include "QString"
#include "QFile"
#include "QTextStream"
#include <stdlib.h>
#include <typeinfo>
#include <ctype.h>
#include "QJsonObject"
#include "QJsonDocument"
#include <unistd.h>
#include <vector>
#include "mainwindow.h"

using namespace std;
using std::string;

StringParse::StringParse()
{

}

QJsonObject StringParse::parse(vector<string> line){
    if(i >= line.size()){
        QJsonObject termino = makeJson("Finish", "Finish", "Finish");
        return termino;
    }

 }

QJsonObject StringParse::writeFile(vector <string> line){

    QJsonObject objeto = getType(line);
    return objeto;
}

void StringParse::readFile(){

}

QJsonObject StringParse::makeJson(string tip, string val, string var){
    QJsonObject object
        {
            {"Type","NI"},
            {"Value","NI"},
            {"Variable","NI"}
        };

        QVariant tipo(QString::fromStdString(tip));
        QVariant valor(QString::fromStdString(val));
        QVariant variable(QString::fromStdString(var));

        object.insert("Type",tipo.toJsonValue());
        object.insert("Value",valor.toJsonValue());
        object.insert("Variable",variable.toJsonValue());
        return object;
}

QJsonObject StringParse::getType(vector<string> line){
    do{
        if(line[0] == "int"){
                string variable  = getVariable(line);
                string valor = getValor(line);
                QJsonObject  objeto = makeJson("int",valor,variable);
                return objeto;
                continue;
        }
        else if(line[0]=="float"){
                string variable  = getVariable(line);
                string valor = getValor(line);
                QJsonObject  objeto = makeJson("float",valor,variable);
                return objeto;
                continue;
        }
        else if(line[0]=="double"){
                string variable  = getVariable(line);
                string valor = getValor(line);
                QJsonObject  objeto = makeJson("double",valor,variable);
                return objeto;
                continue;
            }
        }
        while(i <= line.size());
    QJsonObject  objetof = makeJson("Finish","Finish","Finish");
    return objetof;

}


void StringParse::SplitString(const string& texto, char del, vector<string>& v){

    string::size_type i = 0;
    string::size_type j = texto.find(del);

    while (j != string::npos){
        v.push_back(texto.substr(i,j-i));
        i = ++j;
        j = texto.find(del,j);

        if (j == string::npos){
            v.push_back(texto.substr(i,texto.length()));
        }
    }

    if (v.size() == 0){
        v.push_back(texto.substr(0,1));
    }

}

string StringParse::EliminarEspacios(string texto){

    string resultado;

    while(texto.length() != 0){
        if (texto.length() != 1){
            if(texto[0] == ' ' && texto[1] == ' '){
                texto = texto.substr(1);
            } else if (texto[0] != ' '){
                resultado+=texto[0];
                texto = texto.substr(1);
            }else{
                resultado+='#';
                texto = texto.substr(1);
            }
        } else{
            resultado+=texto[0];
            texto = texto.substr(1);
        }
    }
    return resultado;
}

bool StringParse::VerificarEspacios(vector<string> v) {

    if(v[2] != "="){
        return false;
    }

    for (int i = 0; i < v.size() -1; i ++){
        if (v[i].find(';') != -1){
            return false;
        }
    }

    return true;
}

int StringParse::VerificarNumero(string instruccion) {

    int numeros = 0;
    int letras = 0;
    int puntos = 0;

    for (int i = 0; i < instruccion.length(); ++i) {

        if(instruccion[i] == '0' || instruccion[i] == '1' || instruccion[i] == '2' || instruccion[i] == '3' || instruccion[i] == '4' || instruccion[i] == '5' || instruccion[i] == '6' || instruccion[i] == '7' || instruccion[i] =='8' || instruccion[i] == '9'){
            numeros++;
        } else if (instruccion[i] == '.'){
            puntos++;
        } else{
            letras++;
        }

    }

    if(numeros == 0 && letras == 0){
        return 0;
    } else if (numeros != 0 && letras != 0){
        return 0;
    } else if (numeros != 0 && puntos == 1){
        return 1;
    } else if (numeros == 0 && letras != 0 && puntos == 0){
        return 2;
    } else{
        return 1;
    }


}

string StringParse::ObtenerNumero(string name) {

    int accion = VerificarNumero(name);

    if (accion == 1){
        return name;
    } else if (accion == 2){
        //RecogerValor
    } else{
        return "error";
    }
}

void StringParse::VerificarPuntoyComa(vector<string> &line) {
    string puntoComa = line.back();
    puntoComa.pop_back();
    line.pop_back();
    line.push_back(puntoComa);
    line.push_back(";");
}

int StringParse::VerificarCout(string instruccion) {
    int comillas = 0;
    int letras = 0;
    int numeros= 0;

    for (int i = 0; i < instruccion.length(); ++i) {

        if(instruccion[i] == '0' || instruccion[i] == '1' || instruccion[i] == '2' || instruccion[i] == '3' || instruccion[i] == '4' || instruccion[i] == '5' || instruccion[i] == '6' || instruccion[i] == '7' || instruccion[i] =='8' || instruccion[i] == '9'){
            numeros++;
        } else if (instruccion[i] == '\''){
            comillas++;
        } else{
            letras++;
        }

    }

    if(numeros == 0 && letras == 0){
        return 0;
    } else if (comillas == 2){
        return 1;
    } else if (numeros == 0 && letras != 0){
        return 2;
    }
}

string StringParse::GenerarInt(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }

    if(VerificarEspacios(line)){

        int valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stoi(valor1);
        } else{
            return "error";
        }

        for (int i = 4; i < line.size()-1; ++i) {

            if(line.at(i) == "+"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor += stoi(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "-"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor -= stoi(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "*"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor *= stoi(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "/"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor /= stoi(valor1);
                } else{
                    return "error";
                }

            }

        }


        mensaje = line[0] + "-" + line[1] + "-" + to_string(valor);
        return mensaje;

    }

    return "error";
}

string StringParse::GenerarChar(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }

    if(VerificarEspacios(line)){
        string enviarMensaje = line[0] + "-" + line[1] + "-" + line[3];
        return enviarMensaje;
    }

    return "error";
}

string StringParse::GenerarDouble(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    if(VerificarEspacios(line)){
        double valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stod(valor1);
        } else if (line.size() >= 4) {
            return "error";
        }else {
            return "error";
        }

        for (int i = 4; i < line.size()-1; ++i) {

            if(line.at(i) == "+"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor += stod(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "-"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor -= stod(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "*"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor *= stod(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "/"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor /= stod(valor1);
                } else{
                    return "error";
                }

            }

        }


        mensaje = line[0] + "-" + line[1] + "-" + to_string(valor);
        return mensaje;
    }
    return "error";
}

string StringParse::GenerarLong(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }
    if(VerificarEspacios(line)){

        long valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stol(valor1);
        } else{
            return "error";
        }

        for (int i = 4; i < line.size()-1; ++i) {

            if(line.at(i) == "+"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor += stol(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "-"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor -= stol(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "*"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor *= stol(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "/"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor /= stol(valor1);
                } else{
                    return "error";
                }

            }

        }


        mensaje = line[0] + "-" + line[1] + "-" + to_string(valor);
        return mensaje;
    }

    return "error";
}

string StringParse::GenerarFloat(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }

    if(VerificarEspacios(line)){

        float valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stof(valor1);
        } else{
            return "error";
        }

        for (int i = 4; i < line.size()-1; ++i) {

            if(line.at(i) == "+"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor += stof(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "-"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor -= stof(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "*"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor *= stof(valor1);
                } else{
                    return "error";
                }

            }else if(line.at(i) == "/"){

                valor1 = ObtenerNumero(line.at(i+1));

                if (valor1 != "error"){
                    valor /= stof(valor1);
                } else{
                    return "error";
                }

            }

        }


        mensaje = line[0] + "-" + line[1] + "-" + to_string(valor);
        return mensaje;
    }

    return "error";

}

string StringParse::GenerarCout(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 3) {
        return "error";
    }else {
        return "error";
    }

    int opcion = VerificarCout(line[2]);

    if(opcion == 0){
        return "error";
    } else if (opcion == 1){
        string imprimir = line[2];
        imprimir = imprimir.substr(2,imprimir.length()-2);
        return imprimir;
    } else{
        //pedir valor
    }

    return "error";

}

string StringParse::GenerarReference(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() > 4) {
        return "error";
    }else {
        return "error";
    }


    return "error";
}


string StringParse::getVariable(vector<string> line) {

    string nombreVariable;
    string tipoVariable;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }

    if(VerificarEspacios(line)){

        int valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stoi(valor1);
        } else{
            return "error";
        }

        tipoVariable = "Type " + line[0] + "\n";
        cout << "Type " + line[0] + "\n";
        nombreVariable = line[1];
        cout << "Nombre " + line[1] + "\n";
        return nombreVariable;
    }
}

string StringParse::getValor(vector<string> line) {

    string valorVariable;

    if (line[line.size()-1].find(';') != -1){
        VerificarPuntoyComa(line);
    } else if (line.size() >= 4) {
        return "error";
    }else {
        return "error";
    }

    if(VerificarEspacios(line)){

        int valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            valor += stoi(valor1);
        } else{
            return "error";
        }

        valorVariable = to_string(valor);
        cout << "Valor " + to_string(valor)+ "\n";
        return valorVariable;
    }
}

string StringParse::getValorChar(vector<string> line) {

    string valorVariable;

    valorVariable = line[3];
    cout << "Nombre " + line[3] + "\n";
    return valorVariable;
}
