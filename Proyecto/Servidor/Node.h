//
// Created by richmond on 5/5/21.
//

#ifndef SERVIDOR_NODE_H
#define SERVIDOR_NODE_H

#include <iostream>

using namespace std;


class Node{
public:

    int index;
    string data;
    string name;

    Node(){}

    Node(string dataValue,string nameValue);

    string GetData();

    string GetName();

    int GetIndex();

    void PlusIndex();

    void SetData(string value);

    ~Node();



};

#endif //SERVIDOR_NODE_H
