#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class Span {

public:

    Span(void);
    Span(unsigned int n);
    Span(Span const &copy);
    Span& operator=(Span const& copy);
    ~Span();

    class SpanExceptionFull : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class SpanExceptionNoNumber : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void                addNumber(int number)      throw(SpanExceptionFull);
    int                 shortestSpan()             throw(SpanExceptionNoNumber);
    int                 longestSpan()              throw(SpanExceptionNoNumber);
    void                fillSpan(int nRandNumbers) throw(Span::SpanExceptionFull);
    std::vector<int>    getVector(void) const;

private:

    unsigned int        _n;
    std::vector<int>    _vector;

};

std::ostream &operator<<(std::ostream &out, Span &span);

#endif