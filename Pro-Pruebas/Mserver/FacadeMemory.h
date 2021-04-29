//
// Created by richmond on 27/4/21.
//

#ifndef MSERVER_FACADEMEMORY_H
#define MSERVER_FACADEMEMORY_H

#include "memoryblock.h"
#include <iostream>
#include <sstream>
#include <QObject>
#include <vector>
#include <QJsonObject>
#include <QVariant>

using namespace std;

class FacadeMemory {

private:

    QJsonObject values{
        {"Addres", "NI"},
        {"Name", "NI"},
        {"Value", "NI"},
        {"Index", "NI"}
    };
    string data;
    MemoryBlock *memBlock = new MemoryBlock();

public:

    void Action(string type, string name, string data);
    void AddInt(string name, string data);
    void AddChar(string name, string data);
    void AddLong(string name, string data);
    void AddDouble(string name, string data);
    void AddFloat(string name, string data);
    void StartBlock();
    void EndBlock();
    void CallGarbajeCollector();
    void GetData(string name);
    void GetValues(string name);

};


#endif //MSERVER_FACADEMEMORY_H
