#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    std::cout << "*** ClapTrap Eleven ***" << std::endl;
    ClapTrap clapEleven("Eleven");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << clapEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapEleven.getAttackDamage() << std::endl;
    clapEleven.setAttackDamage(5);
    clapEleven.attack("Demogorgon");
    clapEleven.takeDamage(15);
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << clapEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << clapEleven.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** ScavTrap One ***" << std::endl;
    ScavTrap scavOne("One");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << scavOne.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scavOne.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << scavOne.getAttackDamage() << std::endl;
    scavOne.setAttackDamage(5);
    scavOne.attack("Demogorgon");
    scavOne.takeDamage(15);
    scavOne.guardGate();
    scavOne.takeDamage(90);
    scavOne.guardGate();
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << scavOne.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scavOne.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << scavOne.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

    std::cout << "*** FragTrap Hopper ***" << std::endl;
    FragTrap fragHopper("Hopper");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << fragHopper.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << fragHopper.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << fragHopper.getAttackDamage() << std::endl;
    fragHopper.setAttackDamage(5);
    fragHopper.attack("Demogorgon");
    fragHopper.takeDamage(15);
    fragHopper.highFivesGuys();
    fragHopper.takeDamage(85);
    fragHopper.highFivesGuys();
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << fragHopper.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << fragHopper.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << fragHopper.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;


}
