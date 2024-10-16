#include "../include/Form.hpp"

Form::Form(void) : _name("Form"), _isSigned(false), _signGrade(10), _executeGrade(10) {
    
    println("Form: Default constructor called.");
}

Form::Form(const &Form copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade()) {

    println("Form: Copy constructor called.");
}

Form& Form::operator=(const &Form copy) {

    if(this != &copy)
        _isSigned = copy.getIsSigned();
    return (*this);
}