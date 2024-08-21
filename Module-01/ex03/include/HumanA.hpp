#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {

public:
    
    HumanA(std::string name, Weapon &weaponA);
    ~HumanA(void);

    void attack(void) const;

private:

    std::string     _name;
    Weapon          &_weaponA;

};

#endif