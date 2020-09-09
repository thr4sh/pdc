#include <QCoreApplication>
#include "decoyduck.h"
#include <memory>
#include <utility>
using std::unique_ptr;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unique_ptr<Duck> t(new DecoyDuck());

    t->display();
    t->fly();
    t->quack();
    return a.exec();
}
