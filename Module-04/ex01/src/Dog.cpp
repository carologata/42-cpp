#include "../include/Dog.hpp"

Dog::Dog(void) {

    std::cout << "Dog: Default Constructor called." << std::endl;
    
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal() {

    std::cout << "Dog: Copy Constructor called." << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy) {

    std::cout << "Dog: Assignment Operator called." << std::endl;

    if(this != &copy) {
        delete _brain;
        _brain = new Brain(*(copy._brain));
        _type = copy._type;
    }
        
    return (*this);
}

Dog::~Dog(void) {

    std::cout << "Dog: Destructor called." << std::endl;
    
    delete _brain;
}

void Dog::makeSound(void) const {

    std::cout << "Dog: Au Au Au" << std::endl;
}

Brain *Dog::getBrain(void) const {

    return (_brain);
}

void Dog::setBrain(Brain *brain) {

    if(_brain != brain)
    {
        for(int i = 0; i < IDEAS_NBR; i++) {
            _brain->setIdea(i, brain->getIdea(i));
        }
    }
}