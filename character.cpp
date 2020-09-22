#include "character.h"

Character::Character()
{

}

void Character::setWeapon(unique_ptr<WeaponBehavior> MYWEAPON)
{
    p = move(MYWEAPON);
}

void King::fight()
{
    throwOnNothing();
    cout << "Here goes the fightin\n";
    for(int i = 0; i < 10; ++i) p->UseWeapon();
}

void Queen::fight()
{
    throwOnNothing();
    cout << "Damn W*men\n";
    for(int i = 0; i < 1; ++i) p->UseWeapon();
}

void Knight::fight()
{
    throwOnNothing();
    cout << "Now thats is a `nife!\n";
    for(int i = 0; i < 11; ++i) p->UseWeapon();
}

void Troll::fight()
{

    cout << "AAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n";
    for(int i = 0; i < 20; ++i) cout << "*Hit*\n";
}
