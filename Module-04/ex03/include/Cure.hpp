#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

public:

    Cure(void);
    Cure(const Cure& copy);
    Cure& operator=(const Cure&);
    ~Cure(void);

    AMateria*   clone(void) const;
    void        use(ICharacter& target);
};

#endif