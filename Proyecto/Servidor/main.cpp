#include <string>
#include "Servidor.h"
#include "FacadeMemory.h"
using namespace std;

int main()
{
    Servidor *server = new Servidor();
    server->StartServer();

    return 0;
}
