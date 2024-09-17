#include "../include/Animal.hpp"

AAnimal::AAnimal(void) : _type("Animal") {

    std::cout << "Animal: Default Constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {

    std::cout << "Animal: Copy Constructor called." << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {

    std::cout << "Animal: Assignment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
    
    return (*this);
}

AAnimal::~AAnimal(void) {

    std::cout << "Animal: Destructor called." << std::endl;
}

void AAnimal::makeSound(void) const {

    std::cout << "Animal: some sound" << std::endl;
}

std::string AAnimal::getType(void) const {

    return (_type);
}