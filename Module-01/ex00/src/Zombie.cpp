#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    
    this->_name = name;
}

Zombie::~Zombie(void) {

    std::cout << _name << " was destroyed." << std::endl;
}

void Zombie::announce(void) const {
    
    std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
