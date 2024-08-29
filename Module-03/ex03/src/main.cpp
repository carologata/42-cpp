#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

    std::cout << "*** ClapTrap Eleven ***" << std::endl;
    DiamondTrap diamondEleven("Eleven");
    std::cout << "Before attack: " << std::endl;
    std::cout << "Hit Points: " << diamondEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << diamondEleven.getAttackDamage() << std::endl;
    diamondEleven.setAttackDamage(5);
    diamondEleven.attack("Demogorgon");
    diamondEleven.takeDamage(15);
    std::cout << "After attack: " << std::endl;
    std::cout << "Hit Points: " << diamondEleven.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondEleven.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << diamondEleven.getAttackDamage() << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl;

}
