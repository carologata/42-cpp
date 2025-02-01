#include "../include/Functions.hpp"

/* Dynamic Cast: A cast is an operator that converts data from one type to another type. 
In C++, dynamic casting is mainly used for safe downcasting at run time. To work on dynamic_cast there must be 
one virtual function in the base class. A dynamic_cast works only polymorphic base class because it uses this 
information to decide safe downcasting. */

/* In C++, dynamic_cast requires the base class to have at least one virtual function because it relies 
on the runtime type information (RTTI) provided by the virtual table (vtable) to perform safe downcasting. 
The vtable is a mechanism used by C++ to support dynamic polymorphism. */

/* Downcasting: Casting a base class pointer (or reference) to a derived class pointer (or reference) is 
known as downcasting. In figure 1  casting from the Base class pointer/reference to the “derived class 1” 
pointer/reference showing downcasting (Base ->Derived class). */

/* Upcasting: Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting. 
In figure 1 Casting from Derived class 2 pointer/reference to the “Base class” pointer/reference showing Upcasting 
(Derived class 2 -> Base Class). */

Base * generate(void) {

    static bool seed = true;

    if (seed) {
        srand(time(NULL));
        seed = false;
    }

    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

/* If you receive a B* p as a parameter and you try to dynamic_cast it to A*, 
the cast will fail because p is not pointing to an object of type A. 
The dynamic_cast will return nullptr in this case
 */

void identify(Base* p) {

    if (dynamic_cast<A*>(p)) 
        std::cout << "Pointer Type A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
        std::cout << "Pointer Type B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "Pointer Type C" << std::endl;
    else 
        std::cerr << "Error: Unknown type" << std::endl;
}

/* When dealing with references instead of pointers, you can use dynamic_cast to safely downcast references. 
If the cast fails, dynamic_cast throws a std::bad_cast exception. */

void identify(Base& p) {
    
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Ref Type A" << std::endl;
        return ;
    }
    catch(std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Ref Type B" << std::endl;
        return ;
    }
    catch(std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Ref Type C" << std::endl;
        return ;
    }
    catch(std::exception&) {}

    std::cerr << "Error: Unknown type" << std::endl;
}