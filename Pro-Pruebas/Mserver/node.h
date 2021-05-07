#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node{
public:

    int index;
    T data;
    string name;

    Node(){}
    /// Constructor
    /// \param dataValue T
    /// \param nameValue String
    Node(T dataValue,string nameValue){
        name = nameValue;
        data = dataValue;
        index = 1;
    }

    /// Devuelve el dato
    /// \return T
    T GetData(){
        return data;
    }

    /// devuelve el nombre
    /// \return string
    string GetName(){
        return name;
    }

    /// Devuelve la cantidad de referencias
    /// \return int
    int GetIndex(){
        return index;
    }

    ///Aumenta el indice
    void PlusIndex(){
        index +=1;
    }

    ///Actualiza el dato
    void SetData(T value){
        data = value;
    }



};

#endif // NODE_H
