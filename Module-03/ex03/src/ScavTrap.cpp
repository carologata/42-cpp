#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {

    std::cout << "ScavTrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {

    std::cout << "ScavTrap " << _name << " constructor called." << std::endl;

    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {

    std::cout << "ScavTrap: Copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {

    std::cout << "ScavTrap: Copy assignment operator called" << std::endl;

    if(this != &copy)
        *this = copy;
    return (*this);
}

ScavTrap::~ScavTrap(void) {

    std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {

    if(_name.empty() || _hitPoints == 0 || _energyPoints == 0 || _attackDamage == 0)
    {
        std::cout << "ScavTrap can not attack: ";
        if(_name.empty())
            std::cout << "Name is not set." << std::endl;
        else if(_hitPoints == 0)
            std::cout << "No hit points." << std::endl;
        else if(_energyPoints == 0)
            std::cout << "No energy points." << std::endl;
        else
            std::cout << "No attack points." << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {

    if(_name.empty() ||_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "ScavTrap can not guard gate: ";
        if(_name.empty())
            std::cout << "No hit points." << std::endl;
        else if(_hitPoints == 0)
            std::cout << "No hit points." << std::endl;
        else if(_energyPoints == 0)
            std::cout << "No energy points." << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}