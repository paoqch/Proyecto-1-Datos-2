#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

#include <QtCore/qglobal.h>
#include "node.h";
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

    Node<int> *mem = (Node<int> *) malloc(1024 * 1024 * 10);

    vector<int> garbage;

public:

    template<class T>
    void AddData(T data, string name) {
        if(garbage.empty()){
            Node<T> *temp = new(mem+size) Node<T>(data,name);
            size++;
        } else{
            Node<T> *temp = new(mem+garbage.back()) Node<T>(data,name);
            garbage.pop_back();
        }

    }


    template<class T>
    void UpdateData(T data, string name) {
        for (int i = 0; i < size ; i++) {
            if (mem[i].GetName() == name){
                mem[i].PlusIndex();
                mem[i].data = data;
            }
        }
    }

    auto GetData(string name){
        for (int i = 0; i < size ; i++) {
            if (mem[i].GetName() == name){
                mem[i].PlusIndex();
                return mem[i].GetData();
            }
        }
    }

    vector<string> GetValues(string name){
        for (int i = 0; i < size ; i++) {
            if (mem[i].GetName() == name) {

                vector<string> dataValues;

                const void *address = static_cast<const void *>(&mem[i]);
                std::stringstream ss;
                ss << address;
                std::string nameAddres = ss.str();

                dataValues.push_back(nameAddres);
                dataValues.push_back(to_string(mem[i].GetData()));
                dataValues.push_back(mem[i].GetName());
                dataValues.push_back(to_string(mem[i].GetIndex()));

                return dataValues;
            }
        }
    }

    void Delete() {
        for (int i = 0; i < size; i++) {
            if (mem[i].GetIndex() == 1) {
                garbage.push_back(i);
            }
        }
    }

    void Imprimir() {
        for (int i = 0; i < size; i++) {
            cout << mem[i].GetName() << endl;
        }
    }

    void Start(){
        start = size;
    }

    void Finish(){
        finish = size;
    }

    void DeleteBlockMemory(){
        for(int i = this->start; i != finish; i ++){
            mem[i].name = "error";
            mem[i].data = NULL;
            garbage.push_back(i);
        }
    }


};
#endif // MEMORYBLOCK_H
