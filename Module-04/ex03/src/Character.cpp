#include "../include/Character.hpp"

Character::Character(void) : _name("") {

    std::cout << "Character: Default Constructor called." << std::endl;

    for(int i = 0; i < INVENTORY_SIZE; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name) {

    std::cout << "Character: Parameterized Constructor called." << std::endl;

    for(int i = 0; i < INVENTORY_SIZE; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character& copy) {

    std::cout << "Character: Copy Constructor called." << std::endl;

    for(int i = 0; i < INVENTORY_SIZE; i++)
        _inventory[i] = NULL;
    *this = copy;
}

Character& Character::operator=(const Character& copy) {

    std::cout << "Character: Assignment Operator called." << std::endl;

    if(this != &copy) {
        _name = copy.getName();
        for(int i = 0; i < INVENTORY_SIZE; i++) {
            if(_inventory[i])
                delete _inventory[i];
            if(copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone(); 
        }
    }

    return (*this);
}

Character::~Character(void) {

    std::cout << "Character: Destructor called." << std::endl;
}

std::string const &Character::getName() const {

    return (_name);
}

void Character::equip(AMateria* m) {

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(_inventory[i] == NULL && m != NULL) {
            _inventory[i] = m;
            std::cout << "Character " << _name << " equiped with materia " << m->getType() << std::endl;
            break ;
        }
    }
}

void Character::unequip(int idx) {

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(i == idx && _inventory[i]) {
            std::cout << "Character " << _name << "unequiped with materia " << _inventory[i]->getType() << std::endl;
            _inventory[i] = NULL;
            break ;
        }
    }
}

void Character::use(int idx, ICharacter& target) {

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(i == idx && _inventory[i]) {
            _inventory[i]->use(target);
            _inventory[i] = NULL;
            break ;
        }
    }
}
