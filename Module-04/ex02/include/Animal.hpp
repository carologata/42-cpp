#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#define PRINT_BLUE_BOLD(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

class AAnimal {

public:
    
    AAnimal(void);
    AAnimal(const AAnimal& copy);
    AAnimal& operator=(const AAnimal& copy);
    virtual ~AAnimal(void);

    virtual void    makeSound(void) const = 0;
    std::string     getType(void) const;

protected:

    std::string _type;

};

#endif