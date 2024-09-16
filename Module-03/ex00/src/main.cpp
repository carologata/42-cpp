#include "../include/ClapTrap.hpp"

int main(void) {


    std::cout << "*** ClapTrap Blue 🔵 and Green 🟢 ***" << std::endl;
    std::cout << "*** Default Constructor ***" << std::endl;
    ClapTrap blue;
    ClapTrap green;
    blue.setName("Blue");
    green.setName("Green");
    std::cout << "*** Blue Points ***" << std::endl;
    printPoints(blue);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** Blue attacks Green ***" << std::endl;
    blue.attack("Green");
    std::cout << "*** Set 2 attack damage points for Blue ***" << std::endl;
    blue.setAttackDamage(2);
    std::cout << "*** Blue attacks Green***" << std::endl;
    blue.attack("Green");
    green.takeDamage(blue.getAttackDamage());
    std::cout << "*** Blue Points ***" << std::endl;
    printPoints(blue);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;


    std::cout << "*** ClapTrap Yellow 🟡 and Green 🟢 ***" << std::endl;
    std::cout << "*** Parametrized Constructor ***" << std::endl;
    ClapTrap yellow("Yellow");
    std::cout << "*** Set 3 attack damage points for Yellow ***" << std::endl;
    yellow.setAttackDamage(3);
    std::cout << "*** Yellow Points ***" << std::endl;
    printPoints(yellow);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** Yellow attacks Green until Yellow has no more Enery Points***" << std::endl;
    while(yellow.getEnergyPoints() > 0)
    {
        yellow.attack("Green");
        green.takeDamage(yellow.getAttackDamage());
    }
    std::cout << "*** Yellow Points ***" << std::endl;
    printPoints(yellow);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;


    std::cout << "*** ClapTrap Pink 🟣 and Green 🟢 ***" << std::endl;
    std::cout << "*** Copy Constructor ***" << std::endl;
    ClapTrap pink(yellow);
    std::cout << "*** Set 3 attack damage points for Pink ***" << std::endl;
    pink.setAttackDamage(3);
    std::cout << "*** Set name Pink for Pink ***" << std::endl;
    pink.setName("Pink");
    std::cout << "*** Pink Points ***" << std::endl;
    printPoints(pink);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** Pink attacks Green ***" << std::endl;
    pink.attack("Green");
    std::cout << "*** Set 4 energy points for Pink ***" << std::endl;
    pink.setEnergyPoints(4);
    std::cout << "*** Green is repaired ***" << std::endl;
    green.beRepaired(5);
    std::cout << "*** Pink attacks Green ***" << std::endl;
    pink.attack("Green");
    green.takeDamage(pink.getAttackDamage());
    std::cout << "*** Pink Points ***" << std::endl;
    printPoints(pink);
    std::cout << "*** Green Points ***" << std::endl;
    printPoints(green);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;
}
