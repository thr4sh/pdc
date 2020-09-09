#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H
#include "duck.h"

class RubberDuck : public Duck
{
private:
    unique_ptr<FlyBeh> flb;
    unique_ptr<QuackBeh> qkb;
public:
    RubberDuck();
    virtual void quack();
    virtual void fly();
    virtual void display() {};
};

#endif // RUBBERDUCK_H
