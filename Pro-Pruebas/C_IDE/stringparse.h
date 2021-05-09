#ifndef STRINGPARSE_H
#define STRINGPARSE_H

#include <QtCore/qglobal.h>
#include "Cliente.h"
#include "json.hpp"
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
/**
 * @brief The StringParse class
 */
class StringParse
{
public:

    Cliente *cliente = new Cliente();
    vector<string> linesCode;

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
    string PedirDato(string nameData);
    string GenerarInicio();
    string GenerarFinal();


};

#endif // STRINGPARSE_H
