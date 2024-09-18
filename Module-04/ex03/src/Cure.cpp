#include "../include/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    
    std::cout << "Cure: Default Constructor called." << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy) {

    std::cout << "Cure: Parameterized Constructor called." << std::endl;

    *this = copy;
}

Cure& Cure::operator=(const Cure& copy) {

    std::cout << "Cure: Assignment Operator called." << std::endl;
    
    (void)copy;
    _type = "cure";
    return (*this);
}

Cure::~Cure(void) {

    std::cout << "Cure: Destructor called." << std::endl;
}

AMateria* Cure::clone(void) const {

    return (new Cure(*this));
}

void Cure::use(ICharacter& target) {

    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}