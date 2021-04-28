#include <string>
#include <typeinfo>
#include <QString>
#include <QJsonObject>
#include "memoryblock.h"
#include <iostream>

using namespace std;
struct Node{
    int value;
    float valuefloat;
    long valuelong;
    double valuedouble;
    char valuechar;
    QString type;
    QString label;
    Node *next;
    void* ptr;
    QString address;
};
class variables{

public:
    variables();
    QString preparation(QJsonObject object);

    Malloc* mallocPtr;

    string analizarValor(string valor , string tipo);
};
