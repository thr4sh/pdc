#ifndef WEAPONBEHAVIOR_H
#define WEAPONBEHAVIOR_H

#include <iostream>
#include <memory>
#include <exception>
using namespace std;

class WeaponBehavior
{
public:
    WeaponBehavior();

    void virtual UseWeapon() = 0;

    virtual ~WeaponBehavior() {};

};

class SwordBehaviour : public WeaponBehavior
{
public:
    void virtual UseWeapon();
};

class KnifeBehaviour : public WeaponBehavior
{
public:
    void virtual UseWeapon();
};

class BowAndArrowBehaviour : public WeaponBehavior
{
public:
    void virtual UseWeapon();
};

class AxeBehaviour : public WeaponBehavior
{
public:
    void virtual UseWeapon();
};

#endif // WEAPONBEHAVIOR_H
