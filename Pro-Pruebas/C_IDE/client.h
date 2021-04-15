#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QtNetwork/QTcpSocket>

//se comunica con el Server y el IDE
class Client : public QObject{
    Q_OBJECT

public:
    Client(QObject * obj = 0,QString add="localhost", quint16 port = 4000);
    QJsonObject jsonActual;
    bool mensajeRecibido;
    void SendData(QString data);
    virtual ~Client();

private slots:
    void ReadData();
    void connected();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
