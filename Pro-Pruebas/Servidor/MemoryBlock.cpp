//
// Created by richmond on 5/5/21.
//

#include "MemoryBlock.h"

void MemoryBlock::AddData(string data, string name) {
    Node *temp =  new(mem+size) Node(data,name);
    size++;
}

void MemoryBlock::UpdateData(string data, string name) {
    for (int i = 0; i < size ; i++) {
        if (mem[i].GetName() == name){
            mem[i].PlusIndex();
            mem[i].data = data;
        }
    }
}

string MemoryBlock::GetData(string name) {
    for (int i = 0; i < size; i++) {
        if (mem[i].GetName() == name) {
            mem[i].PlusIndex();
            return mem[i].GetData();
        }
    }
}

vector<string> MemoryBlock::GetValues(int id) {
    for (int i = 0; i < size ; i++) {
        if (i == id) {

            vector<string> dataValues;

            const void *address = static_cast<const void *>(&mem[i]);
            std::stringstream ss;
            ss << address;
            std::string nameAddres = ss.str();

            dataValues.push_back(nameAddres);
            dataValues.push_back(mem[i].GetData());
            dataValues.push_back(mem[i].GetName());
            dataValues.push_back(to_string(mem[i].GetIndex()));


            return dataValues;
        }
    }
}

void MemoryBlock::Delete() {
    for (int i = 0; i < size; i++) {
        if (mem[i].GetIndex() == 1) {
            garbage.push_back(i);
        } else{
            notGarbage.push_back(i);
        }
    }
    RefactorCollector();
}

void MemoryBlock::Imprimir() {
    for (int i = 0; i < size; i++) {
        cout << mem[i].GetName() << endl;
    }
}

void MemoryBlock::Start() {
    start = size;
}

void MemoryBlock::Finish() {
    finish = size-1;
}

int MemoryBlock::GetSize() {
    return size;
}

void MemoryBlock::Refactor() {
    int j = finish+1;
    int newSize = size - ((finish-start) + 1);

    for (int i = start; i < newSize; ++i) {
        mem[i] = mem[j];
        j++;
    }
    size = newSize;
}

void MemoryBlock::RefactorCollector() {
    iCollector = size-1;
    size-=garbage.size();
    for (int i = 0; i < garbage.size(); i++) {
        if(RefactorCollectorAux()){
            if(NotVerificar()){
                mem[garbage.at(i)] = mem[iCollector];
                iCollector--;
            }
        }
    }
    garbage.clear();
    notGarbage.clear();
}

bool MemoryBlock::RefactorCollectorAux() {
    for (int i = garbage.size()-1; i != -1; i--) {

        if(Verificar()) {
            return true;
        } else{
            iCollector--;
        }
    }
    return false;
}

bool MemoryBlock::Verificar() {
    int validar = 0;
    for (int j = garbage.size()-1; j != -1 ; j--) {
        if(garbage.at(j) == iCollector){
            validar++;
        }
    }
    if(validar==0){
        return true;
    }else{
        return false;
    }
}

bool MemoryBlock::NotVerificar() {
    int validar = 0;
    for (int i = 0;i < notGarbage.size();i++){
        if (notGarbage.at(i) == iCollector){
            validar++;
        }
    }

    if(validar != 0){
        return true;
    } else{
        return false;
    }
}

void MemoryBlock::Reset() {
    size = 0;
}