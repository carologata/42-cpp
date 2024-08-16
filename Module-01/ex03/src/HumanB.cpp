#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    
    _name = name;
    _weaponB = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon &weaponB) {

    _weaponB = &weaponB;
}

void HumanB::attack(void) {

    if(_weaponB == NULL)
        std::cout << _name << " has no weapon to attack" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weaponB->getType()  << std::endl;
}