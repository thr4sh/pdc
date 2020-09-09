#include "mallardduck.h"

MallardDuck::MallardDuck() : flb(new FlyWithWings), qkb(new Quack)
{

}

void MallardDuck::quack()
{
    qkb->quack();
}
void MallardDuck::fly()
{
    flb->fly();
}

void MallardDuck::display()
{
    cout << "Just a mallard duck\n";
}
