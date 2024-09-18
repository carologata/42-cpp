#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void) {
    
    std::cout << "*** FragTrap Orange 🍊 and Purple 🍇 ***" << std::endl;
    std::cout << "*** Orange 🍊 Parametrized Constructor ***" << std::endl;
    FragTrap orange("Orange");
    std::cout << "*** Purple 🍇 Copy Constructor from Orange ***" << std::endl;
    FragTrap purple(orange);
    std::cout << "*** Purple 🍇 name: ***" << std::endl;
    std::cout << purple.getName() << std::endl;
    std::cout << "*** Update Purple 🍇 name to Purple: ***" << std::endl;
    purple.setName("Purple");
    std::cout << purple.getName() << std::endl;
    std::cout << "*** Orange 🍊 Points ***" << std::endl;
    printPoints(orange);
    std::cout << "*** Purple 🍇 Points ***" << std::endl;
    printPoints(purple);
    std::cout << "*** Orange 🍊 attacks Purple 🍇 ***" << std::endl;
    orange.attack("purple");
    purple.takeDamage(purple.getAttackDamage());
    std::cout << "*** Orange 🍊 is doing highFive ***" << std::endl;
    orange.highFivesGuys();
    std::cout << "*** Orange 🍊 Points ***" << std::endl;
    printPoints(orange);
    std::cout << "*** Purple 🍇 Points ***" << std::endl;
    printPoints(purple);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** FragTrap Yellow 🍍, Red 🍓 and Brown 🍫 ***" << std::endl;
    std::cout << "*** Yellow 🍍 Parametrized Constructor ***" << std::endl;
    FragTrap yellow("Yellow");
    std::cout << "*** Red 🍓 Copy Constructor from Yellow 🍍 ***" << std::endl;
    FragTrap red = yellow;
    std::cout << "*** Red 🍓 name: ***" << std::endl;
    std::cout << red.getName() << std::endl;
    std::cout << "*** Update Red 🍓 name to Red: ***" << std::endl;
    red.setName("Red");
    std::cout << red.getName() << std::endl;
    std::cout << "*** Brown Parametrized Constructor ***" << std::endl;
    FragTrap brown("Brown");
    std::cout << "*** Yellow is assigned to Brown using Assign Operator ***" << std::endl;
    brown = yellow;
    std::cout << "*** Brown 🍫 name now: ***" << std::endl;
    std::cout << brown.getName() << std::endl;
    std::cout << "*** Yellow 🍍 Points ***" << std::endl;
    printPoints(yellow);
    std::cout << "*** Red 🍓 Points ***" << std::endl;
    printPoints(red);
    std::cout << "*** Brown 🍫 Points ***" << std::endl;
    printPoints(brown);
    std::cout << "*** ***" << std::endl;
}

