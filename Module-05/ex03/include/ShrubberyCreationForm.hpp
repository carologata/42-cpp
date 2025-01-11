#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "../include/AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm(void);

    const std::string getTarget(void) const;
    void              executeTask(void) const;

private:

    std::string _target;
};

#endif