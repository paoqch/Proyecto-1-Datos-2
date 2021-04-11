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
/**
 * @brief Constructor de interface del mserver
 *
 */
class mserver : public QMainWindow
{
    Q_OBJECT

public:
    memory *data= new memory(); /**< Variable de manajador de memoria */
    /**
     * @brief Comunicador de la creacion de la interface
     *
     * @param parent
     */
    explicit mserver(QWidget *parent = 0);
    /**
     * @brief Método para eliminar la creacion de la interface
     *
     */
    ~mserver();

public slots:
    /**
     * @brief Método para establecer la comunicación con el cliente
     *
     */
    void conexion_nueva();
    /**
     * @brief Método para leer los datos enviado por el cliente
     *
     */
    void leer_socketcliente();

private slots:
    /**
     * @brief Método para establecer la conexión con el cliente
     *
     */
    void on_client1_clicked(const QString da);

private:
    Ui::mserver *ui; /**< Interface */
    QTcpServer *tcpmserver; /**< TCP_Mserver */
    QTcpSocket *tcpmainwindow[1]; /**< TCP_Cliente */
};
#endif // MSERVER_H
