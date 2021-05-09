//
// Created by richmond on 6/5/21.
//

#ifndef CLIENTE_CLIENTE_H
#define CLIENTE_CLIENTE_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Cliente {

private:

    string dato;
    char buff[40960];

public:

    void StartClient(string enviar);
    string GetDato();


};


#endif //CLIENTE_CLIENTE_H
