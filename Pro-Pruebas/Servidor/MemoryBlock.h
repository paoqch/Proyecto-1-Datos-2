//
// Created by richmond on 5/5/21.
//

#ifndef SERVIDOR_MEMORYBLOCK_H
#define SERVIDOR_MEMORYBLOCK_H


#include "Node.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

class MemoryBlock {

private:

    int size = 0;
    int start;
    int finish;
    int iCollector;
    bool really = true;

    Node *mem;

    vector<int> garbage;
    vector<int> notGarbage;

public:


    void AddData(string data, string name);
    void UpdateData(string data, string name) ;
    string GetData(string name);
    vector<string> GetValues(int id);
    void Delete();
    void Imprimir();
    void Start();
    void Finish();
    int GetSize();
    void Refactor();
    void RefactorCollector();
    bool RefactorCollectorAux();
    bool Verificar();
    bool NotVerificar();
    void Reset();
    void Reserve(int memory);


};



#endif //SERVIDOR_MEMORYBLOCK_H
