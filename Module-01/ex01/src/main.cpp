#include "Zombie.hpp"

int main(void) {

    int N = 5;
    std::string name = "Hellen";
    Zombie *zombies;
    
    std::cout << "*** HEAP ***" << std::endl;
    std::cout << "*** Calling zombieHorde function with N = " << N << " and name = " << name << ": ***" << std::endl;

    zombies = zombieHorde(N, name);

    std::cout << "*** Executing announce member function for each zombie instance: ***" << std::endl;

    for(int i = 0; i < N; i++)
        zombies[i].announce();

    std::cout << "*** Destroying the instance in the main: ***" << std::endl;
    delete [] zombies;

}