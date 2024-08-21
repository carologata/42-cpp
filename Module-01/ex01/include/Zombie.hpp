#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {

public:

    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

    void    announce(void) const;
    void    setName(std::string name);

private:

    std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif