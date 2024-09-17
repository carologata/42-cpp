#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main(void) {

    PRINT_BLUE_BOLD("*** SUBJECT TESTS ***")

    PRINT_BLUE_BOLD("*** First Subject Test ***")
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    PRINT_BLUE_BOLD("*** ***");

    PRINT_BLUE_BOLD("*** Second Subject Test ***")
    Animal *animals[10];
    PRINT_BLUE_BOLD("*** Cat ***");
    for(int i = 0; i < 5; i++) {
        PRINT_BLUE_BOLD(i);
        animals[i] = new Cat();
        PRINT_BLUE_BOLD("***");
    }
    PRINT_BLUE_BOLD("*** Dog ***");
    for(int i = 5; i < 10; i++) {
        PRINT_BLUE_BOLD(i);
        animals[i] = new Dog();
        PRINT_BLUE_BOLD("***");
        
    }
    PRINT_BLUE_BOLD("*** Delete animal ***");
    for(int i = 0; i < 10; i++) {
        PRINT_BLUE_BOLD(i);
        delete animals[i];
        PRINT_BLUE_BOLD("***");
    }
    PRINT_BLUE_BOLD("*** ***");
    std::cout << std::endl; 


    PRINT_BLUE_BOLD("*** MY OWN TESTS ***");

    PRINT_BLUE_BOLD("*** New Dog Bob 🐕 ***");
    Dog *myDogBob = new Dog();
    PRINT_BLUE_BOLD("*** New Brain ***");
    Brain *myDogBrain = new Brain();
    myDogBrain->setIdea(0, "I love my owner");
    myDogBrain->setIdea(1, "I love bones");
    myDogBob->setBrain(myDogBrain);
    PRINT_BLUE_BOLD("*** Check Dog Bob 🐕 Brain first and second idea ***");
    std::cout << myDogBob->getBrain()->getIdea(0) << std::endl;
    std::cout << myDogBob->getBrain()->getIdea(1) << std::endl;
    PRINT_BLUE_BOLD("*** New Dog Jimmy 🦮 Copy from Bob 🐕 ***");
    Dog myDogJimmy = *myDogBob;
    // Dog *myDogJimmy = myDogBob; //IT DOES NOT WORK IN THE ASSIGN OPERATOR
    PRINT_BLUE_BOLD("*** Check Dog Jimmy 🦮 Brain first and second idea ***");
    std::cout << myDogJimmy.getBrain()->getIdea(0) << std::endl;
    std::cout << myDogJimmy.getBrain()->getIdea(1) << std::endl;

    PRINT_BLUE_BOLD("*** Delete ***");
    delete myDogBob;
    delete myDogBrain;
    PRINT_BLUE_BOLD("*** ***");
    std::cout << std::endl; 

    PRINT_BLUE_BOLD("*** New Dog Tina 🐶🩷  ***");
    Dog myDogTina;
    PRINT_BLUE_BOLD("*** Tina 🐶🩷  New Brain ***");
    Brain *myDogTinaBrain = new Brain();
    myDogTinaBrain->setIdea(0, "I love playing with ball");
    myDogTinaBrain->setIdea(1, "I love eating bananas");
    myDogTina.setBrain(myDogTinaBrain);
    PRINT_BLUE_BOLD("*** Check Dog Tina 🐶🩷  Brain first and second idea ***");
    std::cout << myDogTina.getBrain()->getIdea(0) << std::endl;
    std::cout << myDogTina.getBrain()->getIdea(1) << std::endl;

    PRINT_BLUE_BOLD("*** New Dog Billie 🐶💙 ***");
    Dog myDogBillie;
    PRINT_BLUE_BOLD("*** Billie 🐶💙 New Brain ***");
    Brain *myDogBillieBrain = new Brain();
    myDogBillieBrain->setIdea(0, "I love playing with boxes");
    myDogBillieBrain->setIdea(1, "I love eating apples");
    myDogBillie.setBrain(myDogBillieBrain);
    PRINT_BLUE_BOLD("*** Check Dog Billie 🐶💙 Brain first and second idea ***");
    std::cout << myDogBillie.getBrain()->getIdea(0) << std::endl;
    std::cout << myDogBillie.getBrain()->getIdea(1) << std::endl;

    PRINT_BLUE_BOLD("*** Assign Operator Tina 🐶🩷  equals Bob 🐶💙 ***");
    myDogTina = myDogBillie;
    PRINT_BLUE_BOLD("*** Check Dog Tina 🐶🩷  Brain new first and second idea now ***");
    std::cout << myDogTina.getBrain()->getIdea(0) << std::endl;
    std::cout << myDogTina.getBrain()->getIdea(1) << std::endl;
 
    PRINT_BLUE_BOLD("*** Delete ***");
    delete myDogTinaBrain;
    delete myDogBillieBrain;
    PRINT_BLUE_BOLD("*** ***");
    std::cout << std::endl; 
    
    PRINT_BLUE_BOLD("*** Dog 🐶 pointed by Animal Pointer ***");
    Animal *myAnimal = new Dog();
    myAnimal->makeSound();
    Animal *tmp = myAnimal;
    PRINT_BLUE_BOLD("*** Animal Pointer now pointers to Cat 🐱 ***");
    myAnimal = new Cat();
    myAnimal->makeSound();

    PRINT_BLUE_BOLD("*** Delete ***");
    delete tmp;
    delete myAnimal;

    PRINT_BLUE_BOLD("*** ***");   
    
    return 0;
}
