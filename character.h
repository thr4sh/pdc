#ifndef CHARACTER_H
#define CHARACTER_H

#include "weaponbehavior.h"
class Character
{
protected:
    unique_ptr<WeaponBehavior> p;

    void throwOnNothing()
    {
        if(!p)
            throw runtime_error("lol cant fight without a weapon unless you are a Troll\n");
    }

public:
    Character();

    void virtual fight() = 0;
    void setWeapon(unique_ptr<WeaponBehavior> MYWEAPON);

    virtual ~Character() {};
};


class King : public Character
{
public:
    void virtual fight();
};

class Queen : public Character
{
public:
    void virtual fight();
};

class Knight : public Character
{
public:
    void virtual fight();
};

class Troll: public Character
{
public:
    void virtual fight();
};

#endif // CHARACTER_H
