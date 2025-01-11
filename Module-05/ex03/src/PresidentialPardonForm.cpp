#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
        
    println("PresidentialPardonForm: Default constructor called");
    _target = "presidential default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
        
    println("PresidentialPardonForm: Parameter constructor called");
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {
        
    println("PresidentialPardonForm: Copy constructor called");
    this->_target = copy.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
        
    println("PresidentialPardonForm: Assignment operator called");
        
    if (this != &copy) {
        this->_target = copy.getTarget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
        
    println("PresidentialPardonForm: Destructor called");
}

const std::string PresidentialPardonForm::getTarget(void) const {
        
    return this->_target;
}

void PresidentialPardonForm::executeTask(void) const {

    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}