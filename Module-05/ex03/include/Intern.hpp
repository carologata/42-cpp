#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <exception>

class Intern {

public:

    Intern(void);
    Intern(const Intern& copy);
    Intern& operator=(const Intern& copy);
    ~Intern(void);

    AForm* makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif