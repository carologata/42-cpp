#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void) {

    printlnBlue("*** Bureaucrat 1, 2 and 3 ***");
    Bureaucrat bureaucrat1("Bureaucrat1", 147);
    std::cout << bureaucrat1 << std::endl;
    Bureaucrat bureaucrat2("Bureaucrat2", 24);
    std::cout << bureaucrat2 << std::endl;
    Bureaucrat bureaucrat3("Bureaucrat3", 3);
    std::cout << bureaucrat3 << std::endl;
    printlnBlue("*** ***");

    printlnBlue("*** ShrubberyCreationForm ***");
    ShrubberyCreationForm shrubberyCreationForm1("pink");
    printlnBlue("Bureaucrat1 tries to sign and execute ShrubberyCreationForm");
    std::cout << bureaucrat1 << std::endl;
    std::cout << shrubberyCreationForm1 << std::endl;
    try {
        bureaucrat1.signForm(shrubberyCreationForm1);
        bureaucrat1.executeForm(shrubberyCreationForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to execute ShrubberyCreationForm (not signed)");
    std::cout << bureaucrat2 << std::endl;
    std::cout << shrubberyCreationForm1 << std::endl;
    try {
        bureaucrat2.executeForm(shrubberyCreationForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to sign ShrubberyCreationForm");
    std::cout << bureaucrat2 << std::endl;
    std::cout << shrubberyCreationForm1 << std::endl;
    try {
        bureaucrat2.signForm(shrubberyCreationForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat3 tries to execute ShrubberyCreationForm");
    std::cout << bureaucrat3 << std::endl;
    std::cout << shrubberyCreationForm1 << std::endl;
    try {
        bureaucrat3.executeForm(shrubberyCreationForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("*** ***");
    
    printlnBlue("*** RobotomyRequestForm ***");
    RobotomyRequestForm robotomyRequestForm1("blue");
    printlnBlue("Bureaucrat1 tries to sign and execute RobotomyRequestForm");
    std::cout << bureaucrat1 << std::endl;
    std::cout << robotomyRequestForm1 << std::endl;
    try {
        bureaucrat1.signForm(robotomyRequestForm1);
        bureaucrat1.executeForm(robotomyRequestForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to execute RobotomyRequestForm (not signed)");
    std::cout << bureaucrat2 << std::endl;
    std::cout << robotomyRequestForm1 << std::endl;
    try {
        bureaucrat2.executeForm(robotomyRequestForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to sign RobotomyRequestForm");
    std::cout << bureaucrat2 << std::endl;
    std::cout << robotomyRequestForm1 << std::endl;
    try {
        bureaucrat2.signForm(robotomyRequestForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat3 tries to execute RobotomyRequestForm");
    std::cout << bureaucrat3 << std::endl;
    std::cout << robotomyRequestForm1 << std::endl;
    try {
        bureaucrat3.executeForm(robotomyRequestForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("*** ***");

    printlnBlue("*** PresidentialPardonForm ***");
    PresidentialPardonForm presidentialPardonForm1("yellow");
    printlnBlue("Bureaucrat1 tries to sign and execute PresidentialPardonForm");
    std::cout << bureaucrat1 << std::endl;
    std::cout << presidentialPardonForm1 << std::endl;
    try {
        bureaucrat1.signForm(presidentialPardonForm1);
        bureaucrat1.executeForm(presidentialPardonForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to execute PresidentialPardonForm (not signed)");
    std::cout << bureaucrat2 << std::endl;
    std::cout << presidentialPardonForm1 << std::endl;
    try {
        bureaucrat2.executeForm(presidentialPardonForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat2 tries to sign and execute PresidentialPardonForm");
    std::cout << bureaucrat2 << std::endl;
    std::cout << presidentialPardonForm1 << std::endl;
    try {
        bureaucrat2.signForm(presidentialPardonForm1);
        bureaucrat2.executeForm(presidentialPardonForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("Bureaucrat3 tries to execute PresidentialPardonForm");
    std::cout << bureaucrat3 << std::endl;
    std::cout << presidentialPardonForm1 << std::endl;
    try {
        bureaucrat3.executeForm(presidentialPardonForm1);
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("*** ***");

    return (0);
}