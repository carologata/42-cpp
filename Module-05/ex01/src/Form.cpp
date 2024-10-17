#include "../include/Form.hpp"

Form::Form(void) : _name("Form"), _isSigned(false), _signGrade(10), _executeGrade(10) {
    
    println("Form: Default constructor called.");
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {

    if(signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if(signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade()) {

    println("Form: Copy constructor called.");
}

Form& Form::operator=(const Form& copy) {

    if(this != &copy)
        _isSigned = copy.getIsSigned();
    return (*this);
}

Form::~Form(void) {

    println("Form: Destructor called.");
}

void Form::beSigned(Bureaucrat& bureaucrat) {

    if(bureaucrat.getGrade() <= _signGrade && bureaucrat.getGrade() <= _executeGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::string Form::getName(void)const {

    return (_name);
}

bool Form::getIsSigned(void) const {

    return (_isSigned);
}

int Form::getSignGrade(void) const {

    return (_signGrade);
}

int Form::getExecuteGrade(void) const {

    return (_executeGrade);
}

const char *Form::GradeTooHighException::what() const throw() {

    return ("Form: Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {

    return ("Form: Grade too low.");
}

std::ostream& operator<<(std::ostream& COUT, const Form& form) {

    COUT << "Form " << form.getName() << ", sign grade " << form.getSignGrade();
    COUT << ", execute grade " << form.getExecuteGrade();
    COUT << (form.getIsSigned() ? " is signed." : " is not signed.") << std::endl; 
    
    return (COUT);
}