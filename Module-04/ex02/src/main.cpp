#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main(void) {

    PRINT_BLUE_BOLD("*** SUBJECT TESTS from ex01 ***")

    PRINT_BLUE_BOLD("*** First Subject Test ***")
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    PRINT_BLUE_BOLD("*** ***");

    PRINT_BLUE_BOLD("*** Second Subject Test ***")
    AAnimal *animals[10];
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

    PRINT_BLUE_BOLD("*** Dog 🐶 pointed by Animal Pointer ***");
    AAnimal *myAnimal = new Dog();
    myAnimal->makeSound();
    AAnimal *tmp = myAnimal;
    PRINT_BLUE_BOLD("*** Animal Pointer now pointers to Cat 🐱 ***");
    myAnimal = new Cat();
    myAnimal->makeSound();
    PRINT_BLUE_BOLD("*** Delete ***");
    delete tmp;
    delete myAnimal;
    PRINT_BLUE_BOLD("*** ***");   

    // PRINT_BLUE_BOLD("*** Try to create an instance of Animal ***");
    // AAnimal bigAnimal = new Animal(); //it does not compile
    // AAnimal smallAnimal; //it does not compile     

    return 0;
}
