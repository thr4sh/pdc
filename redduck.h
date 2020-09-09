#ifndef REDDUCK_H
#define REDDUCK_H
#include "duck.h"

class Redduck : public Duck
{
private:
    unique_ptr<FlyBeh> flb;
    unique_ptr<QuackBeh> qkb;
public:
    Redduck();
    virtual void quack();
    virtual void fly();
    virtual void display();
};

#endif // REDDUCK_H
