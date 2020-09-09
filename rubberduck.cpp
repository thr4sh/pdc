#include "rubberduck.h"

RubberDuck::RubberDuck() : flb(new NoFly), qkb(new Squeak)
{

}
void RubberDuck::quack()
{
    qkb->quack();
}
void RubberDuck::fly()
{
    flb->fly();
}
