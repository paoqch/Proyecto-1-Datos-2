//
// Created by richmond on 5/5/21.
//

#ifndef SERVIDOR_SERVIDOR_H
#define SERVIDOR_SERVIDOR_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "FacadeMemory.h"

using namespace std;


class Servidor {

private:


    char buf[40960];
    FacadeMemory *fMem = new FacadeMemory();

public:

    void StartServer();

};


#endif //SERVIDOR_SERVIDOR_H
