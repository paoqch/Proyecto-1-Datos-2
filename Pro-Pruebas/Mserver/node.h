#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;


using namespace std;

template <class T>
class Node{
public:

    int index;
    T data;
    string name;

    Node(){}

    Node(T dataValue,string nameValue){
        name = nameValue;
        data = dataValue;
        index = 1;
    }

    T GetData(){
        return data;
    }

    string GetName(){
        return name;
    }

    int GetIndex(){
        return index;
    }

    void PlusIndex(){
        index +=1;
    }

    void SetData(T value){
        data = value;
    }



};

#endif // NODE_H
