#ifndef DECOYDUCK_H
#define DECOYDUCK_H
#include "duck.h"

class DecoyDuck : public Duck
{
private:
    unique_ptr<FlyBeh> flb;
    unique_ptr<QuackBeh> qkb;
public:
    DecoyDuck();

    virtual void quack();
    virtual void fly();
    virtual void display();
};

#endif // DECOYDUCK_H
