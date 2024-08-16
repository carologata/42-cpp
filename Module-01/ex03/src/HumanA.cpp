#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponA) : _name(name), _weaponA(weaponA) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {

    std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}