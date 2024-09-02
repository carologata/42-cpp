#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {

    std::cout << "DiamondTrap: Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {

    std::cout << "DiamondTrap " << _name << " constructor called." << std::endl;

    FragTrap::_hitPoints    = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {

    std::cout << "DiamondTrap: Copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {

    std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
    if(this != &copy)
        *this = copy;
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {

    std::cout << "DiamondTrap " << _name << ": Destructor called" << std::endl; 
}

void DiamondTrap::attack(const std::string& target) {
    
    ScavTrap::attack(target);  
}

void DiamondTrap::whoAmI(void) {

    std::cout << "I am DiamondTrap " << _name << " and I am also ClapTrap " << ClapTrap::_name << std::endl;
}
