#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

public:
    
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& copy);
    ~WrongAnimal(void);

    void            makeSound(void) const;
    std::string     getType(void) const;

protected:

    std::string _type;

};

#endif