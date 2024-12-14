#include "../include/AForm.hpp"

AForm::AForm(void) : _name("Default AForm"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
    
    println("AForm: Default constructor called.");
} 

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    
    println("AForm: Parametrized constructor called.");
    
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if(gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()) {
    
    println("AForm: Copy constructor called.");
}

AForm& AForm::operator=(const AForm& copy) {
    
    println("AForm: Assignment operator called.");
    
    if(this != &copy) {
        _isSigned = copy.getIsSigned();
    }
    return (*this);
}

AForm::~AForm(void) {
    
    println("AForm: Destructor called.");
}

const std::string AForm::getName(void) const {
    
    return (_name);
}

bool AForm::getIsSigned(void) const {
    
    return (_isSigned);
}

int AForm::getGradeToSign(void) const {
    
    return (_gradeToSign);
}

int AForm::getGradeToExecute(void) const {
    
    return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    
    if(bureaucrat.getGrade() > _gradeToSign) {   
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    
   return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
    
    return ("Grade too low.");
}

std::ostream& operator<<(std::ostream& COUT, const AForm& form) {

    COUT << form.getName() << ", grade to sign is " << form.getGradeToSign() << ", grade to execute is ";
    COUT << form.getGradeToExecute() << " and the form is " << (form.getIsSigned() ? "signed." : "not signed.");
    return (COUT);
}