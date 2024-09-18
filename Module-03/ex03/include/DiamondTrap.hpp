#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:

    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& copy);
    DiamondTrap& operator=(const DiamondTrap& copy);
    ~DiamondTrap(void);

    void            whoAmI(void);

    std::string     getName(void);
    void            setName(std::string name);

private:

    std::string _name;
};

#endif
