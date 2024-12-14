#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default Name"), _grade(150) {

    println("Bureaucrat: Default constructor called.");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

    println("Bureaucrat: Parametrized constructor called.");
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {

    println("Bureaucrat: Copy constructor called.");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {

    println("Bureaucrat: Assignment operator called.");
    
    if(this != &copy) {
        _grade  = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    
    println("Bureaucrat: Destructor called.");
}

const std::string Bureaucrat::getName(void) const {

    return (_name);
}

int Bureaucrat::getGrade(void) const {

    return (_grade);
}

void Bureaucrat::increment(void) {

    try {
        if(_grade <= 1) {
            throw Bureaucrat::GradeTooHighException();
        }
        _grade--;
    } catch (std::exception &e) {
        println(e.what());
    }
}

void Bureaucrat::decrement(void) {
    
    try {
        if(_grade >= 150) {
            throw Bureaucrat::GradeTooLowException();
        }
        _grade++;
    } catch (std::exception &e) {
        println(e.what());
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {

    return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

    return ("Grade too low.");
}