#include "weaponbehavior.h"

WeaponBehavior::WeaponBehavior()
{

}

void SwordBehaviour::UseWeapon()
{
    cout << "Swing-swing\n";
}

void KnifeBehaviour::UseWeapon()
{
    cout << "Now its time for the good ol` lil' chop-chop!\n\n";
}

void BowAndArrowBehaviour::UseWeapon()
{
    cout << "Whoosh-Whoosh\n";
}

void AxeBehaviour::UseWeapon()
{
    cout << "Rub-rub\n";
}
