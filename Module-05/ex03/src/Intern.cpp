#include "../include/Intern.hpp"

Intern::Intern(void) {
    
    println("Intern: Default constructor called.");
}

Intern::Intern(const Intern& copy) {
    
    println("Intern: Copy constructor called.");
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    
    println("Intern: Assignation operator called.");
    if (this == &copy)
        return *this;
    return *this;
}

Intern::~Intern(void) {
    
    println("Intern: Destructor called.");
}

const char *Intern::FormNotFoundException::what(void) const throw() {
    
    return("Form not found.");
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    
    int indice = -1;
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        throw FormNotFoundException();
    }
    
    std::cout << "Intern creates " << formName << "." << std::endl;

    switch (indice)
    {
        case 0:
            return (new ShrubberyCreationForm(target));
        case 1:
            return (new RobotomyRequestForm(target));
        case 2:
            return (new PresidentialPardonForm(target));
        default:
            return (NULL);
    }
}