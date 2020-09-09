#include "redduck.h"

Redduck::Redduck() : flb(new FlyWithWings), qkb(new Quack)
{

}

void Redduck::quack()
{
    qkb->quack();
}
void Redduck::fly()
{
    flb->fly();
}


void Redduck::display()
{
    cout << "This is a red duck\n";
}
