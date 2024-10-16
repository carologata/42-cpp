#include "../include/Bureaucrat.hpp"

int main(void) {

    printBlue("*** Constructor Tests ***");
    printBlue("");
    printBlue("b1 🔴 Default constructor");
    Bureaucrat b1;
    std::cout << b1 << std::endl;
    printBlue("");
    printBlue("b2 🟠 Parametrized constructor");
    Bureaucrat b2("b2", 30);
    std::cout << b2 << std::endl;
    printBlue("");
    printBlue("b3 🟢 Copy constructor from b2 🟠");
    Bureaucrat b3(b2);
    std::cout << b3 << std::endl;
    printBlue("");
    printBlue("b1 🔴 Assignment operator from b3 🟢");
    b1 = b3;
    std::cout << b1 << std::endl;
    printBlue("*** ***\n");

    printBlue("*** Exception Constructor Test ***");
    printBlue("");
    printBlue("Try to create b4 🟣 with a grade higher than 150");
    try {
        Bureaucrat b4("b4", 153);
    } 
    catch(const Bureaucrat::GradeTooHighException& e) {
        println(e.what());
    }
    printBlue("");
    printBlue("Try to create b4 🟣 with a grade lower than 1");
    try {
        Bureaucrat b4("b4", -5);
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        println(e.what());
    }
    printBlue("*** ***\n");
    
    printBlue("*** Increment and Decrement Tests ***");
    printBlue("");
    printBlue("Current attributes b2 🟠");
    std::cout << b2 << std::endl;
    printBlue("");
    printBlue("Increment b2 🟠");
    b2.increment();
    std::cout << b2 << std::endl;
    printBlue("");
    printBlue("Decrement b2 🟠");
    b2.decrement();
    std::cout << b2 << std::endl;
    printBlue("");
    printBlue("Create b4 🟣 with a grade of 1");
    Bureaucrat b4("b4", 1);
    std::cout << b4 << std::endl;
    printBlue("");
    printBlue("Try to decrement b4 🟣");
    try {
        b4.decrement();
    } 
    catch(Bureaucrat::GradeTooLowException& e) {
        println(e.what());
    }
    printBlue("*** ***\n");
}