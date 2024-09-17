#include "../include/AMateria.hpp"

AMateria::AMateria(void) : _type("") {

    std::cout << "AMateria: Default Constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {

    std::cout << "AMateria: Parameterized Constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& copy) {

    std::cout << "AMateria: Copy Constructor called." << std::endl;

    *this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy) {
    
    std::cout << "AMateria: Assignment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
    return (*this);
}

AMateria::~AMateria(void) {
    
    std::cout << "AMateria: Destructor called." << std::endl;
}

std::string const &AMateria::getType() const {

    return (_type);
}

void AMateria::use(ICharacter& target) {

    std::cout << "AMateria: materia used at " << target.getName() << std::endl;
}