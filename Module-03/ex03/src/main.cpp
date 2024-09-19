#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

    std::cout << "*** DiamondTrap Peach 🍑 ***" << std::endl; 
    std::cout << "*** Peach 🍑 Default Constructor ***" << std::endl;
    DiamondTrap peach;
    printPoints(peach);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** DiamondTrap Blue 🔵 ***" << std::endl;
    std::cout << "*** Default Constructor ***" << std::endl;
    DiamondTrap blue("Blue");
    std::cout << "*** Blue Points ***" << std::endl;
    printPoints(blue);
    std::cout << "*** Blue attacks Something ***" << std::endl;
    blue.attack("Something");
    std::cout << "*** Blue says WhoAmI ***" << std::endl;
    blue.whoAmI();
    std::cout << "*** Blue Points ***" << std::endl;
    printPoints(blue);
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** DiamondTrap Green 🟢 ***" << std::endl;
    std::cout << "*** Green 🟢 Copy Constructor from Blue 🔵 ***" << std::endl;
    DiamondTrap green(blue);
    std::cout << "*** Green 🟢 name: ***" << std::endl;
    std::cout << green.getName() << std::endl;
    std::cout << "*** Update Green 🟢 name to Green: ***" << std::endl;
    green.setName("Green");
    std::cout << green.getName() << std::endl;
    std::cout << "*** Green 🟢 says WhoAmI ***" << std::endl;
    green.whoAmI();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** DiamondTrap Orange 🟡 ***" << std::endl;
    std::cout << "*** Default Constructor ***" << std::endl;
    DiamondTrap orange("Orange");
    std::cout << "*** Orange 🟡 is assigned to Green 🟢 using Assign Operator ***" << std::endl;
    green = orange;
    std::cout << "*** Green 🟢 says WhoAmI ***" << std::endl;
    green.whoAmI();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;
}
