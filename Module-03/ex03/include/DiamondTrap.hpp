#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:

    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& copy);
    DiamondTrap& operator=(const DiamondTrap& copy);
    ~DiamondTrap(void);

    void attack(const std::string& target);
    void whoAmI(void);

private:

    std::string _name;
};

#endif
