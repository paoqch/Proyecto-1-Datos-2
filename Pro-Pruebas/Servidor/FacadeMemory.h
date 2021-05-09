//
// Created by richmond on 5/5/21.
//

#ifndef SERVIDOR_FACADEMEMORY_H
#define SERVIDOR_FACADEMEMORY_H


#include "MemoryBlock.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class FacadeMemory {

private:

    MemoryBlock *memBlock = new MemoryBlock();

public:

    string data;
    void ReceiveJson(string stringObj);
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
    string GenerateString();
    void GetAllsValues();

};


#endif //SERVIDOR_FACADEMEMORY_H
