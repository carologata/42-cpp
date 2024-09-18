#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter {

public:

    Character(void);
    Character(std::string name);
    Character(const Character& copy);
    Character& operator=(const Character& copy);
    ~Character(void);

    std::string const & getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);

private:

    std::string     _name;
    AMateria        *_inventory[INVENTORY_SIZE];

};

#endif