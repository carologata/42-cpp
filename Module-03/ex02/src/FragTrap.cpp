#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

    std::cout << "FragTrap: Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

    std::cout << "FragTrap: " << _name << " constructor called." << std::endl;

    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {

    std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {

    std::cout << "FragTrap: Copy assignment operator called" << std::endl;

    if(this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
}

FragTrap::~FragTrap(void) {

    std::cout << "FragTrap " << _name << ": Destructor called" << std::endl; 
}

void FragTrap::highFivesGuys(void) {

    if(_name.empty() || _hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "FragTrap can not do 🖐️ : ";
        if(_hitPoints == 0)
            std::cout << "No hit points." << std::endl;
        else if(_name.empty())
            std::cout << "Name is not set." << std::endl;
        else
            std::cout << "No energy points." << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << ":  🖐️" << std::endl;
}