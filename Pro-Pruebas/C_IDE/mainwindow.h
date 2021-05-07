#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QMainWindow>
#include <string>

#else
#include <QtGui/QMainWindow>
#endif
#include <iostream>
#include <string>
#include <vector>
#include "stringparse.h"
using namespace std;

/**
 * Clase MainWindow
 * Interfaz que permite escribir codigo
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int i = 0;
    StringParse parser;
    vector<string> linesCode;
    StringParse *convertidor = new StringParse();

private slots:
    // acciones de botones
    void on_RunButton_clicked();
    void on_clear_clicked();
    void on_stop_clicked();
    void on_pushButton_clicked();
    void on_Next_clicked();

    void addOutputArea();
    void addStdOutArea(QString linea);

    // agregar datos a la tabla
    void addMemoryDirection(int fila, QString address);
    void addValor(int fila, QString value);
    void addEtiqueta(int fila, QString label);
    void addReferencia(int fila);


    void createClient();
    void sendData(string data);
    void reiniciarParseo();


private:
   Ui::MainWindow *ui;
   enum Columna{
       Direccion,Valor,Etiqueta, Referencias
   };
};

#endif // MAINWINDOW_H
