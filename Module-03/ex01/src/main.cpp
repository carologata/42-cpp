#include "../include/ScavTrap.hpp"

int main(void) {

    std::cout << "*** ScavTrap Orange 🍊 and Purple 🍇 ***" << std::endl;
    
    std::cout << "*** Orange Parametrized Constructor ***" << std::endl;
    ScavTrap orange("Orange");
    std::cout << "*** Purple Copy Constructor from Orange ***" << std::endl;
    ScavTrap purple(orange);
    std::cout << "*** Purple name: ***" << std::endl;
    std::cout << purple.getName() << std::endl;
    std::cout << "*** Update Purple name to Purple: ***" << std::endl;
    purple.setName("Purple");
    std::cout << purple.getName() << std::endl;
    std::cout << "*** Orange Points ***" << std::endl;
    printPoints(orange);
    std::cout << "*** Purple Points ***" << std::endl;
    printPoints(purple);
    std::cout << "*** Orange attacks Purple ***" << std::endl;
    orange.attack("purple");
    purple.takeDamage(purple.getAttackDamage());
    std::cout << "*** Orange is on guard ***" << std::endl;
    orange.guardGate();
    std::cout << "*** Orange Points ***" << std::endl;
    printPoints(orange);
    std::cout << "*** Purple Points ***" << std::endl;
    printPoints(purple);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** ScavTrap Yellow 🍍 and Red 🍓 ***" << std::endl;
    std::cout << "*** Yellow Parametrized Constructor ***" << std::endl;
    ScavTrap yellow("Yellow");
    std::cout << "*** Red is constructed using assigned operator ***" << std::endl;
    ScavTrap red = yellow;
    std::cout << "*** Red name: ***" << std::endl;
    std::cout << red.getName() << std::endl;
    std::cout << "*** Update Red name to Red: ***" << std::endl;
    purple.setName("Red");
    std::cout << purple.getName() << std::endl;


}