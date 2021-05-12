//
// Created by richmond on 6/5/21.
//

#include "Node.h"
/// Constructor
/// \param dataValue string
/// \param nameValue string
Node::Node(string dataValue, string nameValue) {
    name = nameValue;
    data = dataValue;
    index = 1;
}

/// Retorna el dato que esta almacenado
/// \return string
string Node::GetData() {
    return data;
}

/// Retorna el nombre del dato
/// \return string
string Node::GetName() {
    return name;
}

/// Retorna la cantidad de referencias del dato
/// \return int
int Node::GetIndex() {
    return index;
}

/// Aumenta en 1 al cantidad de referencias
void Node::PlusIndex() {
    index++;
}

/// Setea el dato
void Node::SetData(string value) {
    data = value;
}

/// Elimina el dato
Node::~Node() {}