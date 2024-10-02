#include "../include/Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    
    std::cout << "Ice: Default Constructor called." << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy) {

    std::cout << "Ice: Copy Constructor called." << std::endl;

    *this = copy;
}

Ice& Ice::operator=(const Ice& copy) {

    std::cout << "Ice: Assignment Operator called." << std::endl;
    
    (void)copy;
    _type = "ice";
    return (*this);
}

Ice::~Ice(void) {

    std::cout << "Ice: Destructor called." << std::endl;
}

AMateria* Ice::clone(void) const {

    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}