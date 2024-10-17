#include "Bureaucrat.hpp"

class Form {

public: 

    Form(void);
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form(void);

    void        beSigned(Bureaucrat& bureaucrat);

    std::string getName(void) const;
    bool        getIsSigned(void) const;
    int         getSignGrade(void) const;
    int         getExecuteGrade(void) const;

    class GradeTooHighException : public std::exception {

        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        
        public:
            virtual const char *what() const throw();
    };

private: 
    
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _executeGrade;

};