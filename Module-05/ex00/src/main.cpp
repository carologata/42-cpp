#include "../include/Bureaucrat.hpp"

int main(void) {

    printBlue("*** Constructor Tests ***");
    
    printBlue("b1 Default constructor");
    Bureaucrat b1;
    printBlue("b1 name: " + b1.getName() + ", 'b1 grade: " + to_string(b1.getGrade()));

    printBlue("b2 Parametrized constructor");
    Bureaucrat b2("b2", 1);
    printBlue("b2 name: " + b2.getName() + ", b2 grade: " + to_string(b2.getGrade()));

    printBlue("b3 Copy constructor from b2");
    Bureaucrat b3(b2);
    printBlue("b3 name: " + b3.getName() + ", b3 grade: " + to_string(b3.getGrade()));

    printBlue("b1 Assignment operator from b3");
    b1 = b3;
    printBlue("b1 name: " + b1.getName() + ", b1 grade: " + to_string(b1.getGrade()));
    
    printBlue("*** Exception Constrctor Tests ***");
    try {
        Bureaucrat b4("b4", 153);
    } 
    catch(const Bureaucrat::GradeTooHighException& e) {
        println(e.what());
    }

    printBlue("*** ***");
    
    printBlue("*** Exception Tests ***");

    try {
        Bureaucrat b4("b4", 152);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        println(e.what());
    }

    try {
        Bureaucrat b4("b4", 152);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        println(e.what());
    }

    printBlue("*** ***");
}