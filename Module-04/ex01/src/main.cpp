#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main(void) {

    std::cout << "*** SUBJECT TESTS ***" << std::endl;
    Animal *animals[10];
    std::cout << "*** Cat ***" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << i << "." << std::endl;
        animals[i] = new Cat();
        std::cout << "***" << std::endl;
    }
    std::cout << "*** Dog ***" << std::endl;
    for(int i = 5; i < 10; i++) {
        std::cout << i << "." << std::endl;
        animals[i] = new Dog();
        std::cout << 
        "***" << std::endl;
    }
    std::cout << "*** Delete animal ***" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << i << "." << std::endl;
        delete animals[i];
        std::cout << "***" << std::endl;
    }
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** MY OWN TESTS ***" << std::endl;
    std::cout << "*** New Dog Bob ***" << std::endl;
    Dog *myDogBob = new Dog();
    std::cout << "*** New Brain ***" << std::endl;
    Brain *myDogBrain = new Brain();
    myDogBrain->setIdea(0, "I love my owner");
    myDogBrain->setIdea(1, "I love bones");
    myDogBob->setBrain(myDogBrain);
    std::cout << "*** Check Dog Bob Brain first idea ***" << std::endl;
    std::cout << myDogBob->getBrain()->getIdea(0) << std::endl;

    std::cout << "*** New Dog Jimmy Copy from Bob ***" << std::endl;
    Dog myDogJimmy = *myDogBob;
    // Dog *myDogJimmy = myDogBob; //IT DOES NOT WORK IN THE ASSIGN OPERATOR
    std::cout << "*** Check Dog Jimmy Brain first idea ***" << std::endl;
    std::cout << myDogJimmy.getBrain()->getIdea(0) << std::endl;
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    delete myDogBob;
    delete myDogBrain;
    
    return 0;
}
