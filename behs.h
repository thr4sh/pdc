#ifndef BEHS_H
#define BEHS_H
#include <iostream>

class FlyBeh
{
public:
    virtual void fly() = 0;

    virtual ~FlyBeh() {};
};

class QuackBeh
{
    public:
    virtual void quack() = 0;
    virtual ~QuackBeh() {};
};

class FlyWithWings : public FlyBeh
{
    public:
    virtual void fly() { std::cout << "flyin with my own wings\n"; }
};

class NoFly : public FlyBeh
{
    public:
    virtual void fly() { std::cout << "I cant breathe\n"; }
};

class Quack : public QuackBeh
{
    public:
    virtual void quack() { std::cout << "Quacking\n";}
};

class MuteQuack : public QuackBeh
{
    public:
    virtual void quack() { std::cout << "*silence*\n";}
};

class Squeak : public QuackBeh
{
    public:
    virtual void quack() { std::cout << "Squeaking\n";}
};
#endif // BEHS_H
