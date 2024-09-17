#include "../include/Brain.hpp"

Brain::Brain(void) {
    
    std::cout << "Brain: Default Constructor called." << std::endl;

    for(int i = 0; i < IDEAS_NBR; i++)
        _ideas[i] = "";
}

Brain::Brain(const Brain& copy) {

    std::cout << "Brain: Copy Constructor called." << std::endl;

    *this = copy;
}

Brain& Brain::operator=(const Brain& copy) {

    std::cout << "Brain: Assignment Operator called. " << std::endl;

    if(this != &copy)
    {
        for(int i = 0; i < IDEAS_NBR; i++)
            _ideas[i] = copy._ideas[i];
    }

    return (*this);
}

Brain::~Brain(void) {

    std::cout << "Brain: Destructor called." << std::endl;
}

std::string Brain::getIdea(int index) const {

    if(index < IDEAS_NBR)
        return (_ideas[index]);
    return (NULL);
}

void Brain::setIdea(int index, std::string idea) {

    if(index < IDEAS_NBR)
        _ideas[index] = idea;
}
