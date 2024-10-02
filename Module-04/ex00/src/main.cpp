#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main(void) {

    {
        std::cout << "*** SUBJECT TESTS - RIGHT ANIMAL ***" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;

        std::cout << "*** ***" << std::endl;
        std::cout << std::endl;
    }
    
    {
        std::cout << "*** SUBJECT TESTS - WRONG ANIMAL ***" << std::endl;
        
        //If in WrongCat constructer it has creates a new object and in destructor if deletes, 
        //whithout virtual destructor it would lead to memory leak

        //WrongCat destructor is not called
        
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        meta->makeSound();

        delete meta;
        delete i;

        std::cout << "*** ***" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "*** MY TESTS ***" << std::endl;

    std::cout << "*** Default Constructor and Dog Pointer 🐶 ***" << std::endl;
    Dog *caramelo = new Dog();
    std::cout << "Type: " << caramelo->getType() << std::endl;
    caramelo->makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** Copy Constructor 🐶 ***" << std::endl;
    Dog tina = *caramelo;
    std::cout << "Type: " << tina.getType() << std::endl;
    tina.makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** Assign Operator Constructor 🐶 ***" << std::endl;
    tina = *caramelo;
    std::cout << "Type: " << tina.getType() << std::endl;
    tina.makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 
    
    std::cout << "*** Copy Constructor and Cat Pointer 🐱 ***" << std::endl;
    Cat *garfield = new Cat();
    std::cout << "Type: " << garfield->getType() << std::endl;
    garfield->makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** Copy Constructor and Animal Pointer ❔ 🐱 ***" << std::endl;
    Animal *myCat = new Cat();
    std::cout << "Type: " << myCat->getType() << std::endl;
    myCat->makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** Copy Constructor and Wrong Animal Pointer ❌ ❔ 🐱 ***" << std::endl;
    WrongAnimal *myWrongCat = new WrongCat();
    std::cout << "Type: " << myWrongCat->getType() << std::endl;
    myWrongCat->makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    std::cout << "*** Method Dispatching ❔ 🐱 ❔ 🐶 ***" << std::endl;
    Animal *allAnimal = new Cat();
    std::cout << "Type: " << allAnimal->getType() << std::endl;
    allAnimal->makeSound();
    Animal *tmp = allAnimal;
    allAnimal = new Dog();
    std::cout << "Type: " << allAnimal->getType() << std::endl;
    allAnimal->makeSound();
    std::cout << "*** ***" << std::endl;
    std::cout << std::endl; 

    delete caramelo;
    delete garfield;
    delete myCat;
    delete myWrongCat;
    delete allAnimal;
    delete tmp;

    return 0;
}