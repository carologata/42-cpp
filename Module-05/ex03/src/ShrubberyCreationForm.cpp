#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {

    println("ShrubberyCreationForm: Default constructor called");
    _target = "shrubbery default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {

    println("ShrubberyCreationForm: Parameter constructor called");
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {

    println("ShrubberyCreationForm: Copy constructor called");
    this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {

    println("ShrubberyCreationForm: Assignment operator called");

    if (this != &copy) {
        this->_target = copy.getTarget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

    println("ShrubberyCreationForm: Destructor called");
}

const std::string ShrubberyCreationForm::getTarget(void) const {

    return this->_target;
}

void ShrubberyCreationForm::executeTask(void) const {

    std::ofstream file((_target + "_shrubbery").c_str());
    if(file.is_open())
    {
        file << "       _-_         \n";
        file << "    /~~   ~~\\     \n";
        file << " /~~         ~~\\  \n";
        file << "{               }  \n";
        file << " \\  _-     -_  /  \n";
        file << "   ~  \\ //  ~     \n";
        file << "_- -   | | _- _    \n";
        file << "  _ -  | |   -_    \n";
        file << "      // \\        ";
    }
    file.close();
}
