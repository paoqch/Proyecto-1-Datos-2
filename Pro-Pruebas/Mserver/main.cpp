#include "mserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mserver* server = new mserver();
    return a.exec();
}
