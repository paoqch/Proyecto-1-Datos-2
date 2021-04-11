#ifndef MEMORY_H
#define MEMORY_H
#include "iostream"
using namespace std;

class memory
{
public:
    char *total = (char *) malloc(1024 * sizeof(int)); //Memoria local
    int param[6] = {4, 8, 1, 4, 8, 4}; // Parametro de bites de cada tipo de dato
    int ref= 0; // Valor de referecnia para operar sobre los valores de memoria
    int *ptr; //puntero null que va a apuntar a memoria */
    int totalm = 1024; //Variable de control
    int *current; //Variable de control para mantener el flujo de los punteros

    /**
     * @brief Constructurar de memoria
     *
     */
    memory();

};

#endif // MEMORY_H
