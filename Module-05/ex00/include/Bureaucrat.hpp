#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define println(text) std::cout << text << std::endl;
#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

class Bureaucrat {

public:

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat(void);

    const std::string     getName(void) const;
    int                   getGrade(void) const;

    void                  increment(void);
    void                  decrement(void);

    class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};

private:

    const std::string   _name;
    int                 _grade;
};

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& bureaucrat);

#endif