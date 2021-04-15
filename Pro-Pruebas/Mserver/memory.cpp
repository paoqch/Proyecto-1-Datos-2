#include "memory.h"
#include <iostream>

using namespace std;

Memory::Memory(int size){
    currentPtr = 0;
    initPtr = malloc(size);
}

// manejo de int en memoria que devuelve puntero de la direccion que ocupa en memoria
int* Memory::addInt(int x){
    charptr = (char*)initPtr;
    intptr = (int*)(charptr+currentPtr);
    *intptr = x;
    currentPtr += 4;
    return intptr;
}

// manejo de long en memoria que devuelve puntero de la direccion que ocupa en memoria
long* Memory::addLong(long x){
    charptr = (char*)initPtr;
    longptr = (long*)(charptr+currentPtr);
    *longptr = x;
    currentPtr += 8;
    return longptr;
}

// manejo de char en memoria que devuelve puntero de la direccion que ocupa en memoria
char* Memory::addChar(char x){
    charptr = (char*)initPtr;
    *(charptr+currentPtr) = x;
    currentPtr += 1;
    return charptr+currentPtr-1;
}

// manejo de double en memoria que devuelve puntero de la direccion que ocupa en memoria
double* Memory::addDouble(double x){
    charptr = (char*)initPtr;
    doubleptr = (double*)(charptr+currentPtr);
    *doubleptr = x;
    currentPtr += 8;
    return doubleptr;
}

// manejo de float en memoria que devuelve puntero de la direccion que ocupa en memoria
float* Memory::addFloat(float x){
    charptr = (char*)initPtr;
    floatptr = (float*)(charptr+currentPtr);
    *floatptr = x;
    currentPtr += 4;
    return floatptr;
}


