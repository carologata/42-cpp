#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap {

public:

    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);
    virtual ~ClapTrap(void);

    virtual void   attack(const std::string& target);
    void           takeDamage(unsigned int amount);
    void           beRepaired(unsigned int amount);

    std::string    getName(void) const;
    int            getHitPoints(void) const;
    int            getEnergyPoints(void) const;
    int            getAttackDamage(void) const;

    void           setName(std::string name);
    void           setHitPoints(int hitPoints);
    void           setEnergyPoints(int energyPoints);
    void           setAttackDamage(int attackDamage);

protected:

    std::string     _name;
    int             _hitPoints;
    int             _energyPoints;
    int             _attackDamage;
};

void printPoints(const ClapTrap &claptrap);

#endif