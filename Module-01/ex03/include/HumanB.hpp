#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {

public:
    
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon &weaponB);
    void attack(void);

private:

    std::string _name;
    Weapon      *_weaponB;

};

#endif