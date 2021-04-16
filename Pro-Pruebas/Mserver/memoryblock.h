#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

#include <QtCore/qglobal.h>
#include "node.h"
#include <iostream>
#include <sstream>

class MemoryBlock {

public:

    int i = 58254;
    int sizeInt = 0;
    int sizeChar = 0;
    int sizeLong = 0;
    int sizeDouble = 0;
    int sizeFloat = 0;

    Node<int>* intArray = new (nothrow) Node<int> [58254];
    Node<char>* charArray = new (nothrow) Node<char> [58254];
    Node<long>* longArray = new (nothrow) Node<long> [58254];
    Node<double>* doubleArray = new (nothrow) Node<double> [58254];
    Node<float>* floatArray = new (nothrow) Node<float> [58254];


    MemoryBlock();


    template<class T>
    void AddData(T data, string name) {

        if (typeid(int) == typeid(data)) {
            intArray[sizeInt] = Node<int>(data, name);
            sizeInt++;
        } else if (typeid(float) == typeid(data)) {
            floatArray[sizeFloat] = Node<float>(data, name);
            sizeFloat++;
        } else if (typeid(long) == typeid(data)) {
            longArray[sizeLong]=Node<long>(data, name);
            sizeLong++;
        } else if (typeid(char) == typeid(data)) {
            charArray[sizeChar] = Node<char>(data, name);
            sizeChar++;
        } else if (typeid(double) == typeid(data)) {
            doubleArray[sizeDouble] = Node<double>(data, name);
            sizeDouble++;
        }


    }

    template<class T>
    void UpdateData(T data, string name){
        if (typeid(int) == typeid(data)) {
            for (int i = 0; i < sizeInt;i++){
                if (intArray[i].GetName() == name){
                    intArray[i].SetData(data);
                    intArray[i].PlusIndex();
                    break;
                }
            }
        } else if (typeid(float) == typeid(data)) {
            for(int i = 0; i < sizeFloat; i++){
                if(floatArray[i].GetName() == name){
                    floatArray[i].SetData(data);
                    floatArray[i].PlusIndex();
                    break;
                }
            }
        } else if (typeid(long) == typeid(data)) {
            for(int i = 0; i < sizeLong; i++) {
                if (longArray[i].GetName() == name) {
                    longArray[i].SetData(data);
                    longArray[i].PlusIndex();
                    break;
                }
            }
        } else if (typeid(char) == typeid(data)) {
            for(int i = 0; i < sizeChar; i++) {
                if (charArray[i].GetName() == name) {
                    charArray[i].SetData(data);
                    charArray[i].PlusIndex();
                    break;
                }
            }
        } else if (typeid(double) == typeid(data)) {
            for(int i = 0; i < sizeDouble; i++) {
                if (doubleArray[i].GetName() == name) {
                    doubleArray[i].SetData(data);
                    doubleArray[i].PlusIndex();
                    break;
                }
            }
        }
    }

    template<class T>
    T GetData(T data, string name){
        if (typeid(int) == typeid(data)) {
            for (int i = 0; i < sizeInt;i++){
                if (intArray[i].GetName() == name){
                    intArray[i].PlusIndex();
                    return intArray[i].GetData();
                }
            }
        } else if (typeid(float) == typeid(data)) {
            for(int i = 0; i < sizeFloat; i++){
                if(floatArray[i].GetName() == name){
                    floatArray[i].PlusIndex();
                    return floatArray[i].GetData();
                }
            }
        } else if (typeid(long) == typeid(data)) {
            for(int i = 0; i < sizeLong; i++) {
                if (longArray[i].GetName() == name) {
                    longArray[i].PlusIndex();
                    return longArray[i].GetData();
                }
            }
        } else if (typeid(char) == typeid(data)) {
            for(int i = 0; i < sizeChar; i++) {
                if (charArray[i].GetName() == name) {
                    charArray[i].PlusIndex();
                    return charArray[i].GetData();
                }
            }
        } else if (typeid(double) == typeid(data)) {
            for(int i = 0; i < sizeDouble; i++) {
                if (doubleArray[i].GetName() == name) {
                    doubleArray[i].PlusIndex();
                    return doubleArray[i].GetData();
                }
            }
        }
    }

    string GetValues(string name){

        for (int i = 0; i < sizeInt; i++){
            if(intArray[i].GetName() == name){
                Node<int> *pointer = &intArray[i];
                return GetDataCode(pointer);
            }
        }

        for(int i = 0; i < sizeDouble; i++){
            if (doubleArray[i].GetName() == name) {
                Node<double> *pointer = &doubleArray[i];
                return this->GetDataCode(pointer);
            }
        }

        for(int i = 0; i < sizeFloat; i++){
            if (floatArray[i].GetName() == name) {
                Node<float> *pointer = &floatArray[i];
                return this->GetDataCode(pointer);
            }
        }

        for(int i = 0; i < sizeLong; i++){
            if (longArray[i].GetName() == name) {
                Node<long> *pointer = &longArray[i];
                return this->GetDataCode(pointer);
            }
        }

        for(int i = 0; i < sizeChar; i++){
            if (charArray[i].GetName() == name) {
                Node<char> *pointer = &charArray[i];
                return this->GetDataCode(pointer);
            }
        }

        return nullptr;

    }

    template<class T>
    string GetDataCode(Node<T> *pointer) {

        string nodeInfo;

        std::ostringstream oss;
        oss << pointer;
        std::string address = oss.str();

        nodeInfo = address + "-" + to_string(pointer->GetData()) + "-" + pointer->GetName() + "-" + to_string(pointer->GetIndex());
        cout << nodeInfo << endl;
        return nodeInfo;
    }


};
#endif // MEMORYBLOCK_H
