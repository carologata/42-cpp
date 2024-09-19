#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

int main(void) {

    PRINT_BLUE_BOLD("*** SUBJECT TESTS ***")
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    PRINT_BLUE_BOLD("*** ***");

    PRINT_BLUE_BOLD("*** MY OWN TESTS ***");
    
    PRINT_BLUE_BOLD("*** ***");   

    return 0;
}


