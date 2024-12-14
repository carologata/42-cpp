#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

    Form(void);
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form(void);

    const std::string   getName(void) const;
    bool                getIsSigned(void) const;
    int                 getGradeToSign(void) const;
    int                 getGradeToExecute(void) const;

    void                beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:

    const std::string  _name;
    bool               _isSigned;
    const int          _gradeToSign;
    const int          _gradeToExecute;
};

std::ostream& operator<<(std::ostream& COUT, const Form& form);

#endif