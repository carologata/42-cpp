#include "../include/Cat.hpp"

Cat::Cat(void) {

    std::cout << "Cat: Default Constructor called." << std::endl;
    
    _type   = "Cat";
    _brain  = new Brain();
}

Cat::Cat(const Cat& copy) : AAnimal() {

    std::cout << "Cat: Copy Constructor called." << std::endl;
    _brain  = new Brain(*(copy._brain));
    _type   = copy._type;
}

Cat& Cat::operator=(const Cat& copy) {

    std::cout << "Cat: Assignment Operator called." << std::endl;

    if(this != &copy) {
        delete _brain;
        _brain  = new Brain(*(copy._brain));
        _type   = copy._type;
    }   
    return (*this);
}

Cat::~Cat(void) {

    std::cout << "Cat: Destructor called." << std::endl;
    
    delete _brain;
}

void Cat::makeSound(void) const {

    std::cout << "Cat: Meow Meow Meow" << std::endl;
}

Brain *Cat::getBrain(void) const {

    return (_brain);
}

void Cat::setBrain(Brain *brain) {

    _brain = brain;
}
