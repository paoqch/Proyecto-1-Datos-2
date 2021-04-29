//
// Created by richmond on 27/4/21.
//

#include "FacadeMemory.h"

/// Elegi la accion de la memoria
/// \param type string
/// \param name string
/// \param data string
void FacadeMemory::Action(string type, string name, string data) {

    if(type == "int"){
        AddInt(name, data);
    } else if (type == "double"){
        AddDouble(name,data);
    }else if (type == "char"){
        AddChar(name,data);
    }else if (type == "float"){
        AddFloat(name,data);
    }else if (type == "long"){
        AddLong(name,data);
    }else if (type == "data"){
        GetData(name);
    }else if (type == "garbage"){
        CallGarbajeCollector();
    }else if (type == "{"){
        StartBlock();
    }else if (type == "}"){
        EndBlock();
    }

}

/// Añade un entero
/// \param name string
/// \param data string
void FacadeMemory::AddInt(string name, string data) {

    int value = stoi(data);
    memBlock->AddData(value,name);

}
/// Añade un double
/// \param name string
/// \param data string
void FacadeMemory::AddDouble(string name, string data) {
    double value = stod(data);
    memBlock->AddData(value,name);
}
/// Añade un char
/// \param name string
/// \param data string
void FacadeMemory::AddChar(string name, string data) {
    char value = data[0];
    memBlock->AddData(value,name);

}
/// Añade un float
/// \param name string
/// \param data string
void FacadeMemory::AddFloat(string name, string data) {
    float value = stof(data);
    memBlock->AddData(value,name);
}
/// Añade un long
/// \param name string
/// \param data string
void FacadeMemory::AddLong(string name, string data) {
    long value = stol(data);
    memBlock->AddData(value,name);
}
/// Devuelve el valor
/// \param name string
/// \param data string
void FacadeMemory::GetData(string name) {
    auto value = memBlock->GetData(name);
    this->data = to_string(value);
}
/// Llama al garbage collector
void FacadeMemory::CallGarbajeCollector() {
    memBlock->Delete();
}
///Inicia bloque de memoria
void FacadeMemory::StartBlock() {
    memBlock->Start();
}
/// Finaliza bloque de memoria
void FacadeMemory::EndBlock() {
    memBlock->Finish();
    memBlock->DeleteBlockMemory();
}
/// Devuelve los valores de un nodo
void FacadeMemory::GetValues(string name) {

    vector<string> valuesStr = memBlock->GetValues(name);

    QVariant addres(QString::fromStdString(valuesStr[0]));
    QVariant nameValue(QString::fromStdString(valuesStr[1]));
    QVariant value(QString::fromStdString(valuesStr[2]));
    QVariant index(QString::fromStdString(valuesStr[3]));

    values.insert("Addres",addres.toJsonValue());
    values.insert("Name",nameValue.toJsonValue());
    values.insert("Value",value.toJsonValue());
    values.insert("Index",index.toJsonValue());

}