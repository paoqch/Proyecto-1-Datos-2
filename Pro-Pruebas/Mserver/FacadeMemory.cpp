//
// Created by richmond on 27/4/21.
//

#include "FacadeMemory.h"

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
void FacadeMemory::AddInt(string name, string data) {

    int value = stoi(data);
    memBlock->AddData(value,name);

}
void FacadeMemory::AddDouble(string name, string data) {
    double value = stod(data);
    memBlock->AddData(value,name);
}

void FacadeMemory::AddChar(string name, string data) {
    char value = data[0];
    memBlock->AddData(value,name);

}

void FacadeMemory::AddFloat(string name, string data) {
    float value = stof(data);
    memBlock->AddData(value,name);
}

void FacadeMemory::AddLong(string name, string data) {
    long value = stol(data);
    memBlock->AddData(value,name);
}

void FacadeMemory::GetData(string name) {
    auto value = memBlock->GetData(name);
    this->data = to_string(value);
}

void FacadeMemory::CallGarbajeCollector() {
    memBlock->Delete();
}

void FacadeMemory::StartBlock() {
    memBlock->Start();
}

void FacadeMemory::EndBlock() {
    memBlock->Finish();
    memBlock->DeleteBlockMemory();
}

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