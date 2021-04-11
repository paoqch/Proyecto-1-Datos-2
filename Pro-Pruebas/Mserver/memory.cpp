#include "memory.h"
#include "iostream"
#include "string"
#include "QString"
using namespace std;

/**
 * @brief Constructor de memory
 *
 */
memory::memory()
{
    ptr=&totalm;
}

/**
 * @brief Método para filtrar los datos
 *
 * @param v
 */
int* memory::filtro(string v) {
    if (v=="int"){
        return refInt();
    }
    if(v=="long"){
        return refLong();
    }
    if(v=="char"){
        return refChar();
    }
    if(v=="float"){
       return refFloat();
    }
    if(v=="double"){
       return refDouble();
    }
    if(v=="ref"){
        return refRef();
    }
    else {
        cout << "tipo desconocido" << endl;
    }
}

/**
 * @brief Método para reservar los bytes correspondientes a un int
 *
 * @return int
 */
int * memory::refInt() {
    if (totalm < 0){
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "int" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr+ref << endl;
    current = ptr + ref ;
    return ptr+ref;

}
/**
 * @brief Método para reservar los bytes correspondientes a un long
 *
 * @return int
 */
int * memory::refLong() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[1];
    cout << "long" << endl;
    cout << ptr << endl;
    ref=3*ref;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un char
 *
 * @return int
 */
int * memory::refChar() {
    if (totalm < 0){
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[2];
    cout << "char" << endl;
    cout << ptr << endl;
    ref++;

    cout<<(ptr+ref)<<endl;
    current = ptr+ref;

    return (current);
}
/**
 * @brief Método para reservar los bytes correspondientes a un float
 *
 * @return int
 */
int * memory::refFloat() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[3];
    cout << "float" << endl;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un double
 *
 * @return int
 */
int * memory::refDouble() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "double" << endl;
    cout << ptr << endl;
    ref= 1.5* ref;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un referencia
 *
 * @return int
 */
int * memory::refRef() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "ref" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}

//filtro para borrar referencias

/**
 * @brief Método para borrar los bytes de las referencia
 *
 * @param v
 */
void memory::eraser(string v)
{
    if (v=="int"){
        delInt();
    }
    if(v=="long"){
        delLong();
    }
    if(v=="char"){
        delChar();
    }
    if(v=="float"){
        delFloat();
    }
    if(v=="double"){
        delDouble();
    }
    if(v=="ref"){
        delRef();
    }
    else{
        cout << "tipo desconocido" << endl;
    }
}


/**
 * @brief Método para borrar los bytes correspondientes a un int
 *
 * @return int
 */
int * memory::delInt() {
    if (totalm >= 10024){
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "int" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr-ref << endl;
    current = ptr - ref ;
    return ptr-ref;

}
/**
 * @brief Método para borrar los bytes correspondientes a un long
 *
 * @return int
 */
int * memory::delLong() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[1];
    cout << "long" << endl;
    cout << ptr << endl;
    ref=3*ref;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a un char
 *
 * @return int
 */
int * memory::delChar() {
    if (totalm >= 10024){
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm - param[2];
    cout << "char" << endl;
    cout << ptr << endl;
    char k;

    cout << ptr-k << endl;
    current = ptr - k ;
    return ptr-k;
}
/**
 * @brief Método para borrar los bytes correspondientes a un float
 *
 * @return int
 */
int * memory::delFloat() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[3];
    cout << "float" << endl;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a un double
 *
 * @return int
 */
int * memory::delDouble() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "double" << endl;
    cout << ptr << endl;
    ref= 1.5* ref;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a una referencia
 *
 * @return int
 */
int * memory::delRef() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "ref" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
