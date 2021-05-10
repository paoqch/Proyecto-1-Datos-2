//
// Created by richmond on 5/5/21.
//

#include "FacadeMemory.h"

/// Elegi la accion de la memoria
/// \param type string
/// \param name string
/// \param data string
void FacadeMemory::Action(string type, string name, string data) {

    if(type == "int"){
        AddInt(name, data);
        GetAllsValues();
    } else if (type == "double"){
        AddDouble(name,data);
        GetAllsValues();
    }else if (type == "char"){
        AddChar(name,data);
        GetAllsValues();
    }else if (type == "float"){
        AddFloat(name,data);
        GetAllsValues();
    }else if (type == "long"){
        AddLong(name,data);
        GetAllsValues();
    }else if (type == "data"){
        GetData(name);
    }else if (type == "garbage"){
        CallGarbajeCollector();
        GetAllsValues();
    }else if (type == "{"){
        StartBlock();
        GetAllsValues();
    }else if (type == "}"){
        EndBlock();
        GetAllsValues();
    }else if (type == "values"){
        GetAllsValues();
    }else if (type == "reset"){
        memBlock->Reset();
    } else if(type == "reserve"){
        memBlock->Reserve(stoi(data));
    }

}

/// Añade un entero
/// \param name string
/// \param data string
void FacadeMemory::AddInt(string name, string data) {
    memBlock->AddData(data,name);
}

/// Añade un double
/// \param name string
/// \param data string
void FacadeMemory::AddDouble(string name, string data) {
    memBlock->AddData(data,name);
}

/// Añade un char
/// \param name string
/// \param data string
void FacadeMemory::AddChar(string name, string data) {
    memBlock->AddData(data,name);
}

/// Añade un float
/// \param name string
/// \param data string
void FacadeMemory::AddFloat(string name, string data) {
    memBlock->AddData(data,name);
}

/// Añade un long
/// \param name string
/// \param data string
void FacadeMemory::AddLong(string name, string data) {
    memBlock->AddData(data,name);
}

/// Devuelve el valor
/// \param name string
/// \param data string
void FacadeMemory::GetData(string name) {
    string send = memBlock->GetData(name);
    json objData;
    objData["getdata"] = "true";
    objData["data"] = send;
    this->data = objData.dump(4);
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
    memBlock->Refactor();
}

void FacadeMemory::ReceiveJson(string stringObj) {
    json obj = json::parse(stringObj);
    string type = obj["type"].get<string>();
    string name = obj["name"].get<string>();
    string value = obj["value"].get<string>();
    this->Action(obj["type"].get<string>(),obj["name"].get<string>(),obj["value"].get<string>());
}

string FacadeMemory::GenerateString() {
    if (this->data == ""){
        return "vacio";
    } else{
        return this->data;
    }
}

void FacadeMemory::GetAllsValues() {

    int size = memBlock->GetSize();
    json objData;

    for (int i = 0; i < size; ++i) {
        vector<string> data = memBlock->GetValues(i);
        objData[to_string(i)]["address"] = data[0];
        objData[to_string(i)]["name"] = data[2];
        objData[to_string(i)]["data"] = data[1];
        objData[to_string(i)]["reference"] = data[3];
    }

    objData["size"] = size;

    this->data = objData.dump(4);

}