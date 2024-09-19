#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define PRINT_BLUE_BOLD(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

class ICharacter;

class AMateria {

public:
    
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(const AMateria& copy);
    AMateria& operator=(const AMateria& copy);
    virtual ~AMateria(void);

    std::string const &     getType(void) const; 
    virtual AMateria*       clone(void) const = 0;
    virtual void            use(ICharacter& target);

protected:

    std::string _type;

};

#endif