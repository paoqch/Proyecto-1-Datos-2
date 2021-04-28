#ifndef STRINGPARSE_H
#define STRINGPARSE_H

#include <QtCore/qglobal.h>

#include "client.h"
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <sstream>
#include "QJsonObject"
#include "QJsonDocument"
#include <string.h>

using namespace std;
using std::string;

class StringParse
{
public:


    StringParse *convertidor = new StringParse();

    vector<string> linesCode;
    int i = 0;
    string entero = "int";
    QJsonObject makeJson(string tip, string val, string var);
    string codigoCompleto;
    QJsonObject parse(vector <string> line);
    QJsonObject writeFile(vector <string> line);
    QJsonObject getType(vector <string> line);
    void readFile();

    StringParse();

    void SplitString(const string& texto, char del, vector<string>& v);
    string EliminarEspacios(string texto);
    bool VerificarEspacios(vector <string> v);
    int VerificarNumero(string instruccion);
    int VerificarCout(string instruccion);
    string GenerarInt(vector <string> line);
    string GenerarChar(vector <string> line);
    string GenerarLong(vector <string> line);
    string GenerarDouble(vector <string> line);
    string GenerarFloat(vector <string> line);
    string GenerarReference(vector <string> line);
    string GenerarCout(vector <string> line);
    string ObtenerNumero(string name);
    void VerificarPuntoyComa(vector<string>& line);


    string getValor(vector<string> line);
    string getValorChar(vector<string> line);
    string getVariable(vector<string> line);
};

#endif // STRINGPARSE_H
