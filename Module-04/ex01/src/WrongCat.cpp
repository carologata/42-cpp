#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) {

    _type = "WrongCat";
    std::cout << "WrongCat: Default Constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal() {

    std::cout << "WrongCat: Copy Constructor called." << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {

    std::cout << "WrongCat: Copy Assingment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
    return (*this);
}

WrongCat::~WrongCat(void) {

    std::cout << "WrongCat: Destructor called." << std::endl;
}

void WrongCat::makeSound(void) const {

    std::cout << "WrongCat: Meow Meow Meow" << std::endl;
}
