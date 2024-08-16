#include "Zombie.hpp"

Zombie::Zombie(void) {
    
    std::cout << "A zombie was constructed." << std::endl;
}

Zombie::Zombie(std::string name) {
    
    this->name = name;
    std::cout << name << " was constructed." << std::endl;
}

Zombie::~Zombie(void) {

    std::cout << name << " was destroyed." << std::endl;
}

void Zombie::announce(void) {
    
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    
    this->name = name;
}
