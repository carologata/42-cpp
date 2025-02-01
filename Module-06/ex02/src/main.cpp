#include "../include/Functions.hpp"

int main(void) {

    std::cout << "Identify A" << std::endl;
    Base *baseA = new A();
    identify(baseA);
    identify(*baseA);
    delete baseA;
    std::cout << "*********" << std::endl;

    std::cout << "Identify B" << std::endl;
    Base *baseB = new B();
    identify(baseB);
    identify(*baseB);
    delete baseB;
    std::cout << "*********" << std::endl;

    std::cout << "Identify C" << std::endl;
    Base *baseC = new C();
    identify(baseC);
    identify(*baseC);
    delete baseC;
    std::cout << "*********" << std::endl;

    std::cout << "Identify Base" << std::endl;
    Base *base = new Base();
    identify(base);
    identify(*base);
    delete base;
    std::cout << "*********" << std::endl;

    std::cout << "Identify Random" << std::endl;
    std::cout << "*********" << std::endl;

    Base *baseRan[10];
    for(int i = 0; i < 10; i++) {
        baseRan[i] = generate();
        identify(baseRan[i]);
        identify(*baseRan[i]);
        std::cout << "*********" << std::endl;
        delete baseRan[i];
    }

    return 0;
}