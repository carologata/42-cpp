#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void) {

    Intern intern;
    Bureaucrat bureaucrat("Bureaucrat", 1);

    printlnBlue("*** Create Forms ***");
    AForm *shrubberyCreationForm = intern.makeForm("shrubbery creation", "pink");
    AForm *robotomyRequestForm = intern.makeForm("robotomy request", "yellow");
    AForm *presidentialPardonForm = intern.makeForm("presidential pardon", "blue");
    printlnBlue("*** ***")
    printlnBlue("*** Create Nonexistent Form ***");
    try {
        AForm *form = intern.makeForm("nonexistent form", "red");
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    printlnBlue("*** ***")

    printlnBlue("*** Sign Forms ***");
    bureaucrat.signForm(*shrubberyCreationForm);
    bureaucrat.signForm(*robotomyRequestForm);
    bureaucrat.signForm(*presidentialPardonForm);
    printlnBlue("*** ***")
    printlnBlue("*** Execute Forms ***");
    bureaucrat.executeForm(*shrubberyCreationForm);
    bureaucrat.executeForm(*robotomyRequestForm);
    bureaucrat.executeForm(*presidentialPardonForm);
    printlnBlue("*** ***")

    delete shrubberyCreationForm;
    delete robotomyRequestForm;
    delete presidentialPardonForm;

    return (0);
}