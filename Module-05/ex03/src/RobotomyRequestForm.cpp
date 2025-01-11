#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
    
    println("RobotomyRequestForm: Default constructor called");
    _target = "robotomy default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
    
    println("RobotomyRequestForm: Parameter constructor called");
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
    
    println("RobotomyRequestForm: Copy constructor called");
    this->_target = copy.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    
    println("RobotomyRequestForm: Assignment operator called");
    
    if (this != &copy) {
        this->_target = copy.getTarget();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    
    println("RobotomyRequestForm: Destructor called");
}

const std::string RobotomyRequestForm::getTarget(void) const {
    
    return this->_target;
}

void RobotomyRequestForm::executeTask(void) const {

    srand(time(NULL)); // This function sets the seed for the random number generator used by rand()
	
    // If you call srand() with the same seed value, rand() will produce the same sequence of numbers each time.
	
    std::cout << "Vrroooom... vr-vr-vr-vr!" << std::endl;
  
	if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
    }
	else {
        std::cout << _target << " robotomization has failed." << std::endl;
	}
}