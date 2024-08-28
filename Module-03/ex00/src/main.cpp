#include "ClapTrap.hpp"

int main(void) {

    std::cout << "*** ClapTrap Eleven ***" << std::endl;
    ClapTrap clapEleven;
    clapEleven.setName("Eleven");
    clapEleven.setHitPoints(20);
    clapEleven.setEnergyPoints(20);
    clapEleven.setAttackDamage(0);
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << clapEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapEleven.getAttackDamage() << std::endl;
    clapEleven.attack("Demogorgon");
    clapEleven.setAttackDamage(2);
    clapEleven.attack("Demogorgon");
    clapEleven.takeDamage(5);
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << clapEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapEleven.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** ClapTrap One ***" << std::endl;
    ClapTrap clapOne("One");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << clapOne.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapOne.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapOne.getAttackDamage() << std::endl;
    clapOne.setAttackDamage(5);
    clapOne.attack("Demogorgon");
    clapOne.takeDamage(15);
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << clapOne.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapOne.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapOne.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** ClapTrap Hopper ***" << std::endl;
    ClapTrap clapHopper(clapOne);
    clapHopper.setName("Hopper");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << clapHopper.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapHopper.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapHopper.getAttackDamage() << std::endl;
    clapOne.setAttackDamage(5);
    clapHopper.attack("Demogorgon");
    clapHopper.takeDamage(5);
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << clapHopper.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapHopper.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapHopper.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;
}
