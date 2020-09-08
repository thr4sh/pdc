#include <QCoreApplication>
#include "mallardduck.h"
#include <memory>
#include <utility>
using std::unique_ptr;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unique_ptr<Duck> t(new MallardDuck());

    t->display();
    t->swim();

    return a.exec();
}
