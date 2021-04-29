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

/**
 * @brief StringParse::StringParse
 */
StringParse::StringParse()
{
    i = 0;
}
/**
 * @brief StringParse::parse
 * @param line
 * @return
 * Mete la informacion recibida y enviada a un area de texto
 */
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

/**
 * @brief StringParse::makeJson
 * @param tip
 * @param val
 * @param var
 * @return
 */
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

/**
 * @brief StringParse::getType
 * @param line
 * @return
 * Identifica el tipo de variable y lo pasa a un Json
 */
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


/// Función split para separar el stiring y generar el vector de string
/// \param texto string que se quiere parsea
/// \param del delimitador
/// \param v vector a cambiar
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
/// Elimina los espacios de un string y delimita los elementos por un -
/// \param texto string a quitar los espacios y remplazarlo por -
/// \return string
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
/// Verifica que la sintaxis está bien
/// \param v vector
/// \return booleano dependiendo si está correcto
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
/// Verifica si el número esta correcto
/// \param instruccion string
/// \return booleano
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
/// Obtiene el número del servidor
/// \param name string
/// \return string
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
/// Verifica si esta el punto y coma
/// \param line &vector
void StringParse::VerificarPuntoyComa(vector<string> &line) {
    string puntoComa = line.back();
    puntoComa.pop_back();
    line.pop_back();
    line.push_back(puntoComa);
    line.push_back(";");
}

/// Verifica si el cout esta bien
/// \param instruccion string
/// \return int
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
/// Genera el string para el int que se envia al servidor
/// \param line vector
/// \return string
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
/// Genera el string para el char que se envia al servidor
/// \param line vector
/// \return string
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
/// Genera el string para el double que se envia al servidor
/// \param line vector
/// \return string
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
/// Genera el long para el double que se envia al servidor
/// \param line vector
/// \return string
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
/// Genera el string para el float que se envia al servidor
/// \param line vector
/// \return string
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
/// Verificar si el cout está correcto
/// \param line vector
/// \return string
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
/// Genera el string para el reference que se envia al servidor
/// \param line vector
/// \return string
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

/**
 * @brief StringParse::getVariable
 * @param line
 * @return
 * Retorna el nombre de las variable
 */
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

/**
 * @brief StringParse::getValor
 * @param line
 * @return
 * Retorna el valor de la variable
 */
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

/**
 * @brief StringParse::getValorChar
 * @param line
 * @return
 * Mete la informacion recibida y enviada a un area de texto
 */
string StringParse::getValorChar(vector<string> line) {

    string valorVariable;

    valorVariable = line[3];
    cout << "Nombre " + line[3] + "\n";
    return valorVariable;
}
