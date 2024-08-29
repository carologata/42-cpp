#ifndef FLAG_TRAP_H
#define FLAG_TRAP_H

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap {

public: 

    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap(void);

    void highFivesGuys(void);

};

#endif