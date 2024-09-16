#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {

    std::cout << "WrongAnimal: Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {

    std::cout << "WrongAnimal: Copy Constructor called." << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {

    std::cout << "WrongAnimal: Copy Assingment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
    
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {

    std::cout << "WrongAnimal: Destructor called." << std::endl;
}

void WrongAnimal::makeSound(void) const {

    std::cout << "WrongAnimal: some sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {

    return (_type);
}