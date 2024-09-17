#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../include/ICharacter.hpp"
#include "../include/AMateria.hpp"

class Character : public ICharacter {

public:

    Character(void);
    Character(const Character& copy);
    Character& operator=(const Character& copy);
    ~Character(void);

    std::string const & getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);

private:

    std::string     _name;
    AMateria        *inventory[4];

};

#endif