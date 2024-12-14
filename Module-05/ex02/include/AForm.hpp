#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:

    AForm(void);
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);
    virtual ~AForm(void);

    const std::string   getName(void) const;
    bool                getIsSigned(void) const;
    int                 getGradeToSign(void) const;
    int                 getGradeToExecute(void) const;

    void                beSigned(const Bureaucrat &bureaucrat);
    virtual void        execute(Bureaucrat const &executor) const = 0; 

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

protected:

    const std::string  _name;
    bool               _isSigned;
    const int          _gradeToSign;
    const int          _gradeToExecute;
};

std::ostream& operator<<(std::ostream& COUT, const Form& form);

#endif