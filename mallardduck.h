#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "duck.h"

class MallardDuck : public Duck
{
private:
    unique_ptr<FlyBeh> flb;
    unique_ptr<QuackBeh> qkb;
public:
    MallardDuck();
    virtual void quack();
    virtual void fly();
    virtual void display();
};

#endif // MALLARDDUCK_H
