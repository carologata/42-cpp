#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {

    println("Bureaucrat: Default constructor called.");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

    println("Bureaucrat: Parametrized constructor called.");

    if(grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if(grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {

    println("Bureaucrat: Copy constructor called.");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {

    println("Bureaucrat: Assignment operator called.");
    
    if(this != &copy)
        _grade  = copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    
    println("Bureaucrat: Destructor called.");
}

std::string Bureaucrat::getName(void) const {

    return (_name);
}

int Bureaucrat::getGrade(void) const {

    return (_grade);
}

void Bureaucrat::increment(void) {

    if(_grade == 150)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade++;
}

void Bureaucrat::decrement(void) {
    
    if(_grade == 1)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade--;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {

    return ("Bureaucrat: Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

    return ("Bureaucrat: Grade too low.");
}
