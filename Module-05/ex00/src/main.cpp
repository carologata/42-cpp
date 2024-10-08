#include "../include/Bureaucrat.hpp"

int main(void) {

    printBlue("*** Constructor Tests ***");
    printBlue("b1 Default constructor");
    Bureaucrat b1;
    printBlue("b2 Parametrized constructor");
    Bureaucrat b2("b2", 1);
    printBlue("b3 Copy constructor from b2");
    Bureaucrat b3(b2);
    printBlue("b4 Assignment operator from b3");
    Bureaucrat b4 = b3;
    printBlue("*** ***");
    
    try {
        Bureaucrat b6("b6", 152);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        println(e.what());
    }
}