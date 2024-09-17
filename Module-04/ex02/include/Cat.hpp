#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

public:
    
    Cat(void);
    Cat(const Cat& copy);
    Cat& operator=(const Cat& copy);
    ~Cat(void);

    void    makeSound(void) const;
    
    Brain   *getBrain(void) const;
    void    setBrain(Brain *brain);

private:

    Brain* _brain;

};

#endif