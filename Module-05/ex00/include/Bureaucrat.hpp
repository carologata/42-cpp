#include <iostream>
#include <string>

#define println(text) std::cout << text << std::endl;

class Bureaucrat {

public:

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat(void);

    std::string     getName(void);
    int             getGrade(void);

    void    increment(void);
    void    decrement(void);

private:

    const std::string   _name;
    int                 _grade;

};