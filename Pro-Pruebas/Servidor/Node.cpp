//
// Created by richmond on 6/5/21.
//

#include "Node.h"

Node::Node(string dataValue, string nameValue) {
    name = nameValue;
    data = dataValue;
    index = 1;
}

string Node::GetData() {
    return data;
}

string Node::GetName() {
    return name;
}

int Node::GetIndex() {
    return index;
}

void Node::PlusIndex() {
    index++;
}

void Node::SetData(string value) {
    data = value;
}

Node::~Node() {}