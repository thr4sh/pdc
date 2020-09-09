#include "decoyduck.h"

DecoyDuck::DecoyDuck() : flb(new NoFly), qkb(new MuteQuack)
{

}

void DecoyDuck::quack()
{
    qkb->quack();
}
void DecoyDuck::fly()
{
    flb->fly();
}

void DecoyDuck::display()
{
    cout << "AAAAAAAAAAAAAHHHHHHHHHHHHHHHHh";
}
