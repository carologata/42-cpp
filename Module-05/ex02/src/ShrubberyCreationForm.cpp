#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {

    println("ShrubberyCreationForm default constructor called");
    _target = "default target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {

    println("ShrubberyCreationForm parameter constructor called");
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {

    println("ShrubberyCreationForm copy constructor called");
    this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {

    println("ShrubberyCreationForm assignation operator called");

    if (this != &copy) {
        this->_target = copy.getTarget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

    println("ShrubberyCreationForm destructor called");
}

const std::string ShrubberyCreationForm::getTarget(void) const {

    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    if (_isSigned == false || executor.getGrade() > _gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream file((_target + "_shrubbery").c_str());
    if(file.is_open())
    {
        file << "       _-_         ";
        file << "    /~~   ~~\\     ";
        file << " /~~         ~~\\  ";
        file << "{               }  ";
        file << " \\  _-     -_  /  ";
        file << "   ~  \\ //  ~     ";
        file << "_- -   | | _- _    ";
        file << "  _ -  | |   -_    ";
        file << "      // \\        ";
    }
    file.close();
}
