#include "Zombie.hpp"

Zombie::Zombie(void) {
    
    std::cout << "A zombie was constructed." << std::endl;
}

Zombie::Zombie(std::string name) {
    
    this->_name = name;
    std::cout << name << " was constructed." << std::endl;
}

Zombie::~Zombie(void) {

    std::cout << _name << " was destroyed." << std::endl;
}

void Zombie::announce(void) const {
    
    std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    
    this->_name = name;
}
