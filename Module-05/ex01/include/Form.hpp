#include "Bureaucrat.hpp"

class Form {

public: 

    Form(void);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form(void);

    void        beSigned(Bureaucrat& bureaucrat);

    std::string getName() const;
    bool        getIsSigned() const;
    int         getSignGrade() const;
    int         getExecuteGrade() const;

private: 
    
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _executeGrade;

};