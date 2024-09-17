#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

public:
    
    Dog(void);
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    ~Dog(void);

    void    makeSound(void) const;

    Brain   *getBrain(void) const;
    void    setBrain(Brain *brain);

private:

    Brain* _brain;
};

#endif