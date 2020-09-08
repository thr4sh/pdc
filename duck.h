#ifndef DUCK_H
#define DUCK_H

#include <iostream>
using std::cout;

class Duck
{
public:
    Duck();
    void  swim();
    void  quack();
    virtual void display() = 0;
};

#endif // DUCK_H
