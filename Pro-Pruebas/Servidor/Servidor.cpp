//
// Created by richmond on 5/5/21.
//

#include "Servidor.h"
/// Servidor, inicia, recibe y envia el dato
void Servidor::StartServer() {

    int listening = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    listen(listening, SOMAXCONN);

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSockect = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    close(listening);


    while (true)
    {
        memset(this->buf, 0, 4096);

        int bytesReceived = recv(clientSockect, this->buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            close(clientSockect);
            this->StartServer();
            break;
        }

        cout << string(this->buf, 0, bytesReceived) << endl;
        fMem->ReceiveJson(string(this->buf, 0, bytesReceived));
        string datasend = fMem->GenerateString();
        fMem->data = "";
        send(clientSockect, datasend.c_str(), strlen(datasend.c_str()) +1 , 0);
        cout << "enviado" << endl;

    }

    close(clientSockect);
}