#ifndef PRESEDENTIALPARDONFORM_HPP
#define PRESEDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
    
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm(void);

    const std::string getTarget(void) const;
    void executeTask(void) const;

private:

    std::string _target;
};

#endif