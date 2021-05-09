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
        return PedirDato(name);
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

    if(numeros != 0 && letras != 0){
        return 0;
    } else if (comillas == 2 && letras == 1 || comillas == 2 && numeros >= 2){
        return 1;
    } else if (numeros == 0 && letras >= 1 && comillas == 0){
        return 2;
    }
}
/// Genera el string para el int que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarInt(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
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

        json obj;

        obj["type"] = line[0];
        obj["name"] = line[1];
        obj["value"] = to_string(valor);

        return obj.dump(4);

    }

    return "error";
}
/// Genera el string para el char que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarChar(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    if(VerificarEspacios(line)){
        json obj;

        obj["type"] = line[0];
        obj["name"] = line[1];
        obj["value"] = line[3];

        return obj.dump(4);
    }

    return "error";
}
/// Genera el string para el double que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarDouble(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    if(VerificarEspacios(line)){
        double valor;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        cout << "este es con qstring " << valor << endl;

        if (valor1 != "error"){

            QString prueba = QString::fromStdString(valor1);
            valor = prueba.toDouble();

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


        json obj;

        obj["type"] = line[0];
        obj["name"] = line[1];
        obj["value"] = to_string(valor);

        return obj.dump(4);
    }
    return "error";
}
/// Genera el long para el double que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarLong(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
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

        json obj;

        obj["type"] = line[0];
        obj["name"] = line[1];
        obj["value"] = to_string(valor);

        return obj.dump(4);
    }

    return "error";
}
/// Genera el string para el float que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarFloat(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    if(VerificarEspacios(line)){

        float valor = 0;
        string valor1;

        valor1 = ObtenerNumero(line.at(3));

        if (valor1 != "error"){
            QString prueba = QString::fromStdString(valor1);
            valor = prueba.toFloat();
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


        json obj;

        obj["type"] = line[0];
        obj["name"] = line[1];
        obj["value"] = to_string(valor);

        return obj.dump(4);
    }

    return "error";

}
/// Verificar si el cout está correcto
/// \param line vector
/// \return string
string StringParse::GenerarCout(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 3){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    int opcion = VerificarCout(line[2]);

    if(opcion == 0){
        return "error";
    } else if (opcion == 1){
        string imprimir = line[2];
        imprimir = imprimir.substr(1,imprimir.length()-2);
        return imprimir;
    } else if (opcion == 2){
        string imprimir = line[2];
        imprimir = imprimir.substr(1,imprimir.length()-2);
        return ObtenerNumero(imprimir);
    }

    return "error";

}
/// Genera el string para el reference que se envia al servidor
/// \param line vector
/// \return string
string StringParse::GenerarReference(vector<string> line) {

    string mensaje;

    if (line[line.size()-1].find(';') != -1 && line.size() >= 4){
        VerificarPuntoyComa(line);
    } else {
        return "error";
    }

    if(line[3] == "&"){
        string dataType = line[1].substr(1,line[1].size()-2);
        string name = line[2];
        //string valor = PedirValor(line[3]);

    } else {
        return "error";
    }

    return "error";
}

string StringParse::PedirDato(string nameData) {

    json obj;

    obj["type"] = "data";
    obj["name"] = nameData;
    obj["value"] = "notValue";

    cout << "me llego esto  " << obj.dump(4);

    cliente->StartClient(obj.dump(4));

    sleep(0.01);

    string recibido = cliente->GetDato();
    obj = json::parse(recibido);

    return obj["data"].get<string>();

}

string StringParse::GenerarFinal() {

    json obj;

    obj["type"] = "}";
    obj["name"] = "notValue";
    obj["value"] = "notValue";

    return obj.dump(4);
}

string StringParse::GenerarInicio() {

    json obj;

    obj["type"] = "{";
    obj["name"] = "notValue";
    obj["value"] = "notValue";

    return obj.dump(4);
}

