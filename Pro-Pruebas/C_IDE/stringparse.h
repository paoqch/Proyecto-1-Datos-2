#ifndef STRINGPARSE_H
#define STRINGPARSE_H

#include <QtCore/qglobal.h>

#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class StringParse
{
public:
    StringParse();
    void SplitString(const string& texto, char del, vector<string>& v);
    string EliminarEspacios(string texto);
};

#endif // STRINGPARSE_H
