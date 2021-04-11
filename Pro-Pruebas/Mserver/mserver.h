#ifndef MSERVER_H
#define MSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include "memory.h"

namespace Ui {
class mserver;
}

class mserver : public QMainWindow
{
    Q_OBJECT

public:
    memory *data= new memory(); // Variable de manejo de memoria
    explicit mserver(QWidget *parent = 0);
    ~mserver();

public slots:
    // establecer la comunicación con el cliente
    void conexion_nueva();
    // leer los datos enviado por el cliente
    void leer_socketcliente();

private slots:
    // establecer la conexión con el cliente
    void on_client1_clicked(const QString da);

private:
    Ui::mserver *ui; /**< Interface */
    QTcpServer *tcpmserver; /**< TCP_Mserver */
    QTcpSocket *tcpmainwindow[1]; /**< TCP_Cliente */
};
#endif // MSERVER_H
