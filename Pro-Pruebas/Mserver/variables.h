#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>
#include <typeinfo>
#include <QString>
#include <QJsonObject>
#include "memoryblock.h"
#include <iostream>
#include <vector>

using namespace std;
using std::string;

/**
 * @brief The variables class
 * Clase encargada de procesar las solicitudes del cliente

 */
class variables{
    public:
        variables();
        int value;
        float valuefloat;
        long valuelong;
        double valuedouble;
        char valuechar;
        QString type;
        QString label;
        void* ptr;
        QString address;
        QString preparation(QJsonObject object);
        string analizarValor(string valor, string tipo);
};

#endif //VARIABLES_H

