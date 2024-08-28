#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {

public:

    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);
    ~ClapTrap(void);

    void           attack(const std::string& target);
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

private:

    std::string     _name;
    int             _hitPoints;
    int             _energyPoints;
    int             _attackDamage;

};

#endif