#include "../include/Form.hpp"

Form::Form(void) : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
    
    println("Form: Default constructor called.");
} 

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    
    println("Form: Parametrized constructor called.");
    
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()) {
    
    println("Form: Copy constructor called.");
}

Form& Form::operator=(const Form& copy) {
    
    println("Form: Assignment operator called.");
    
    if(this != &copy) {
        _isSigned = copy.getIsSigned();
    }
    return (*this);
}

Form::~Form(void) {
    
    println("Form: Destructor called.");
}

const std::string Form::getName(void) const {
    
    return (_name);
}

bool Form::getIsSigned(void) const {
    
    return (_isSigned);
}

int Form::getGradeToSign(void) const {
    
    return (_gradeToSign);
}

int Form::getGradeToExecute(void) const {
    
    return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    
    if(bureaucrat.getGrade() > _gradeToSign) {   
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    
   return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
    
    return ("Grade too low.");
}

std::ostream& operator<<(std::ostream& COUT, const Form& form) {

    COUT << form.getName() << ", grade to sign is " << form.getGradeToSign() << ", grade to execute is ";
    COUT << form.getGradeToExecute() << " and the form is " << (form.getIsSigned() ? "signed." : "not signed.");
    return (COUT);
}