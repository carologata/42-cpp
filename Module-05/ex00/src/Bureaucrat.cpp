#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(-1) {

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
        _name   = copy.getName();
        _grade  = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    
    println("Bureaucrat: Destructor called.");
}

std::string Bureaucrat::getName(void) {

    return (_name);
}

int Bureaucrat::getGrade(void) {

    return (_grade);
}

void Bureaucrat::increment(void) {

    try {
        if(_grade == 150)
            throw Bureaucrat::GradeTooHighException();
        _grade++;
    } 
    catch (Bureaucrat::GradeTooHighException& e) {  
        return ;
    }
    
}