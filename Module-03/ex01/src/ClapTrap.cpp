#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {

    std::cout << "ClapTrap: Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

    std::cout << "ClapTrap " << _name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {

    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {

    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;

    if(this != &copy)
        *this = copy;
    return (*this);
}

ClapTrap::~ClapTrap(void) {

    std::cout << "ClapTrap " << _name << ": Destructor called" << std::endl; 
}

void ClapTrap::attack(const std::string& target) {

    if(_name.empty() || _hitPoints == 0 || _energyPoints == 0 || _attackDamage == 0)
    {
        std::cout << "ClapTrap can not attack: ";
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
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if(_name.empty() || _hitPoints == 0)
    {
        if(_hitPoints == 0)
            std::cout << _name << " is already dead." << std::endl;
        else
            std::cout << "Name is not set." << std::endl;
        return ;
    }
    _hitPoints -= amount;
    if(_hitPoints < 0)
        _hitPoints = 0;
    std::cout << _name << " was attacked, suffering a damage of " << amount << ". It has now " << _hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    
    if(_name.empty() || _hitPoints == 0 || _energyPoints == 0 )
    {
        std::cout << "Can not attack: ";
        if(_name.empty())
            std::cout << "Name is not set." << std::endl;
        else if(_hitPoints == 0)
            std::cout << "No hit points." << std::endl;
        else if(_energyPoints == 0)
            std::cout << "No energy points." << std::endl;
        return ;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "Repair Hit Points: received " << amount << " points. It has now " << _hitPoints << " total points." << std::endl;
}

std::string ClapTrap::getName(void) const {

    return (_name);
}

int ClapTrap::getHitPoints(void) const{

    return (_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {

    return (_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {

    return (_attackDamage);
}

void ClapTrap::setName(std::string name) {

    _name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {

    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {

    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {

    _attackDamage = attackDamage;
}
