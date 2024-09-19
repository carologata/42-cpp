#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name("") {

    std::cout << "DiamondTrap: Default constructor called." << std::endl;

    FragTrap::_hitPoints    = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {

    std::cout << "DiamondTrap " << _name << " constructor called." << std::endl;

    FragTrap::_hitPoints    = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {

    _name = copy._name;
    ClapTrap::_name = copy._name + "_clap_name";

    std::cout << "DiamondTrap: Copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {

    std::cout << "DiamondTrap: Copy assignment operator called." << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
        _name = copy._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {

    std::cout << "DiamondTrap " << _name << ": Destructor called." << std::endl; 
}

void DiamondTrap::whoAmI(void) {

    std::cout << "I am DiamondTrap " << _name << " and I am also ClapTrap " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName(void) {

    return (_name);
}

void DiamondTrap::setName(std::string name) {

    _name = name;
}
