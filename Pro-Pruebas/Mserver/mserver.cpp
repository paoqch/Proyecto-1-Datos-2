#include "mserver.h"
#include "ui_mserver.h"
#include "memory.h"
#include "logger.h"

#include <QJsonObject>
#include <QJsonDocument>

logger *l1 = new logger();

mserver::mserver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mserver)
{
    ui->setupUi(this);
    tcpmserver = new QTcpServer(this);
    tcpmserver->setMaxPendingConnections(1);

    for(int i = 0; i< tcpmserver->maxPendingConnections();i++){
        tcpmainwindow[i] = new QTcpSocket(this);
    }
    tcpmserver->listen(QHostAddress::LocalHost,8888);
    connect(tcpmserver,SIGNAL(newConnection()),this, SLOT(conexion_nueva()));
}


mserver::~mserver()
{
    delete ui;
}

/**
 //crear una nueva conexión
 *
 */
void mserver::conexion_nueva(){
    static int j=0;
    tcpmainwindow[j] = tcpmserver->nextPendingConnection();
    connect(tcpmainwindow[j],SIGNAL(readyRead()),this, SLOT(leer_socketcliente()));
    j++;
    ui->lineEdit->setText(l1->logMessage(0,"Connected Client...10MB saved"));
}

/**
 * @brief Método para establecer una conexión con el cliente
 *
 */
void mserver::on_client1_clicked(const QString dato)
{
    tcpmainwindow[0]->write( dato.toLatin1().data() , dato.toLatin1().size()); //envio datos al cliente
}

