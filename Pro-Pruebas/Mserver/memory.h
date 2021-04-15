#ifndef MEMORY_H
#define MEMORY_H

class Memory
{
public:
    Memory(int size);
    int* addInt(int x);
    char* addChar(char x);
    long* addLong(long x);
    float* addFloat(float x);
    double* addDouble(double x);

private:
    // espcio de memoria para servidor
    void* initPtr;

    // punteros para las variables en el initPtr
    int* intptr;
    char* charptr;
    long* longptr;
    float* floatptr;
    double* doubleptr;

    // posicion de memoria libre
    int currentPtr;
};

#endif // MEMORY_H
