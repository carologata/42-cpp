#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
    
    WrongCat(void);
    WrongCat(const WrongCat& copy);
    WrongCat& operator=(const WrongCat& copy);
    ~WrongCat(void);

    void makeSound(void) const;
};

#endif