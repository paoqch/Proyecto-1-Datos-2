//
// Created by richmond on 6/5/21.
//

#include "Cliente.h"
/// Envia y recibe datos del servidor
/// \param enviar string
void Cliente::StartClient(string enviar) {

    int sock= socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);

    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));

    while(true){

        int sendRes = send(sock, enviar.c_str(), enviar.length(), 0);

        memset(this->buff, 0, 4096);
        int bytesReceived = recv(sock, this->buff, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {

            cout << "SERVER> " << string(this->buff, bytesReceived) << "\r\n";
            this->dato = string(this->buff, bytesReceived);

        }
        break;
    }


    close(sock);
}

/// Retorna el dato enviado por el servidor
/// \return string
string Cliente::GetDato() {
    return dato;
}