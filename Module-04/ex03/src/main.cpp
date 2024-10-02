#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

int main(void) {

    {
        PRINT_BLUE_BOLD("*** SUBJECT TESTS ***")
        PRINT_BLUE_BOLD("*** 1 ***")
        IMateriaSource* src = new MateriaSource();
        PRINT_BLUE_BOLD("*** 2 ***")
        src->learnMateria(new Ice());
        PRINT_BLUE_BOLD("*** 3 ***")
        src->learnMateria(new Cure());
        PRINT_BLUE_BOLD("*** 4 ***")
        ICharacter* me = new Character("me");
        PRINT_BLUE_BOLD("*** 5 ***")
        AMateria* tmp;
        PRINT_BLUE_BOLD("*** 6 ***")
        tmp = src->createMateria("ice");
        PRINT_BLUE_BOLD("*** 7 ***")
        me->equip(tmp);
        PRINT_BLUE_BOLD("*** 8 ***")
        tmp = src->createMateria("cure");
        PRINT_BLUE_BOLD("*** 9 ***")
        me->equip(tmp);
        PRINT_BLUE_BOLD("*** 10 ***")
        ICharacter* bob = new Character("bob");
        PRINT_BLUE_BOLD("*** 11 ***")
        me->use(0, *bob);
        PRINT_BLUE_BOLD("*** 12 ***")
        me->use(1, *bob);
        PRINT_BLUE_BOLD("*** 13 ***")
        delete bob;
        delete me;
        delete src;
        PRINT_BLUE_BOLD("*** ***");
        PRINT_BLUE_BOLD("");
    }

    //RULE
    //All materias used to equip a character must come from MateriaSource creation.
    
    PRINT_BLUE_BOLD("*** MY OWN TESTS ***");

    PRINT_BLUE_BOLD("*** Create colorSource ***");
    IMateriaSource *colorSource = new MateriaSource();
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Create 3 materias ***");
    AMateria *greenIce = new Ice();
    AMateria *whiteCure = new Cure();
    Ice      *redIce = new Ice();
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** colorSource try to learn 3 materias ***");
    colorSource->learnMateria(greenIce);
    colorSource->learnMateria(whiteCure);
    colorSource->learnMateria(redIce);
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Create 2 materias and colorSource try to learn 2 materias at same time ***");
    colorSource->learnMateria(new Ice());
    colorSource->learnMateria(new Cure()); //This one will not be learned because invetory is full
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Create character CheerBear ***");
    Character cheerBear("CheerBear");
    PRINT_BLUE_BOLD("*** CheerBear equiped with Ice directly (Inventory 0) ***");
    cheerBear.equip(colorSource->createMateria("ice"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Cure using tmp (Inventory 1) ***");
    AMateria *tmp = colorSource->createMateria("cure");
    cheerBear.equip(tmp);
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Create character PoliteBear ***");
    ICharacter *politeBear = new Character("PoliteBear");
    PRINT_BLUE_BOLD("*** CheerBear equiped with Ice directly (Inventory 0) ***");
    politeBear->equip(colorSource->createMateria("ice"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Ice directly (Inventory 1) ***");
    politeBear->equip(colorSource->createMateria("ice"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Cure directly (Inventory 2) ***");
    politeBear->equip(colorSource->createMateria("cure"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Cure directly (Inventory 3) ***");
    politeBear->equip(colorSource->createMateria("cure"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Cure directly (Inventory 4) ***");
    politeBear->equip(colorSource->createMateria("cure"));
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Create character FriendBear ***");
    Character friendBear("FriendBear");
    PRINT_BLUE_BOLD("*** CheerBear equiped with Ice directly (Inventory 0) ***");
    friendBear.equip(colorSource->createMateria("ice"));
    PRINT_BLUE_BOLD("*** CheerBear equiped with Cure directly (Inventory 1) ***");
    friendBear.equip(colorSource->createMateria("cure"));
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** CheerBear use Ice 0 on PoliteBear ***");
    cheerBear.use(0, *politeBear);
    PRINT_BLUE_BOLD("*** CheerBear use Ice 0 (does not have anymore) on PoliteBear ***");
    cheerBear.use(0, *politeBear);
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** PoliteBear uses Cure 2 on FriendBear***");
    politeBear->use(2, friendBear);
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** PoliteBear unequip 0 ***");
    politeBear->unequip(0);
    PRINT_BLUE_BOLD("*** PoliteBear unequip 0 (does not have anymore) ***");
    politeBear->unequip(0);
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** FriendBear is assigned to PoliteBear ***");
    *politeBear = friendBear;
    PRINT_BLUE_BOLD("");

    PRINT_BLUE_BOLD("*** Delete ***");
    delete colorSource;
    delete politeBear;

    PRINT_BLUE_BOLD("*** ***");   

    return 0;
}


