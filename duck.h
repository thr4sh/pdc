#ifndef DUCK_H
#define DUCK_H

#include <iostream>
//#include "props.h"
#include "behs.h"
#include <memory>

using std::cout;
using std::unique_ptr;
using std::make_unique;
class Duck
{
public:
    Duck();
    void  swim();

    virtual void fly() = 0;
    virtual void quack() = 0;
    virtual void display() = 0;

    virtual ~Duck() {};
};

#endif // DUCK_H
