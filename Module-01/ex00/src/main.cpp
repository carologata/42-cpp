#include "Zombie.hpp"

int main(void) {
    
    std::cout << "*** HEAP ***" << std::endl;
    std::cout << "*** Calling newZombie function: ***" << std::endl;
    Zombie *heapZombie = newZombie("Hellen");
    std::cout << "*** Back to the main ***" << std::endl;
    std::cout << "*** Executing the member function in the main: ***" << std::endl;
    heapZombie->announce();
    std::cout << "*** Destroying the instance in the main: ***" << std::endl;
    delete heapZombie;

    std::cout << std::endl;

    std::cout << "*** STACK ***" << std::endl;
    std::cout << "*** Calling randomChump function: ***" << std::endl;
    std::cout << "*** The instance will be constructed and destroyed inside the randomChump scope ***" << std::endl;
    randomChump("Stella");
    std::cout << "*** Back to the main ***" << std::endl;

    std::cout << std::endl;

}

/* 
Use stack allocation when the object is small, has a well-defined scope, and needs automatic memory management.
Use heap allocation when the object is large, its lifetime is dynamic, or it needs to persist across different scopes. 
*/