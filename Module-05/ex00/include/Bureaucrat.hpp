#include <iostream>
#include <string>

#define println(text) std::cout << text << std::endl;
#define printBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

class Bureaucrat {

public:

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat(void);

    std::string     getName(void) const;
    int             getGrade(void) const;

    void            increment(void);
    void            decrement(void);

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
    int                 _grade;

};