#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm {

public:

    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm(void);

    const std::string getTarget(void) const;
    void              executeTask(void) const;

private:
    
        std::string _target;
};

#endif