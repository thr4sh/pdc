#include <QCoreApplication>
#include "decoyduck.h"
#include "character.h"
#include <memory>
#include <utility>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unique_ptr<Duck> t(new DecoyDuck());

    t->display();
    t->fly();
    t->quack();

    unique_ptr<Character> p((new Knight()));

    p->setWeapon(make_unique<KnifeBehaviour>());

    p->fight();
    return a.exec();
}
