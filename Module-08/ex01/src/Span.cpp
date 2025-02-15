#include "../include/Span.hpp"

Span::Span(void) : _n(0), _vector() {};

Span::Span(unsigned int n) : _n(n), _vector() {};

Span::Span(Span const &copy) {
    *this = copy;
}

Span& Span::operator=(Span const& copy) {
    if (this != &copy) {
        this->_n      = copy._n;
        this->_vector = copy._vector;
    }
    return *this;
}

Span::~Span() {};

void Span::addNumber(int number) throw (Span::SpanExceptionFull) {

    if (this->_vector.size() >= this->_n)
        throw Span::SpanExceptionFull();
    this->_vector.push_back(number);
}

int Span::shortestSpan() throw (Span::SpanExceptionNoNumber) {

    if (this->_vector.size() < 2)
        throw Span::SpanExceptionNoNumber();

    std::sort(this->_vector.begin(), this->_vector.end());
    int shortest = this->_vector[1] - this->_vector[0];
    for (unsigned int i = 1; i < this->_vector.size(); i++) {
        if (this->_vector[i] - this->_vector[i - 1] < shortest)
            shortest = this->_vector[i] - this->_vector[i - 1];
    }

    return shortest;
}

int Span::longestSpan() throw (Span::SpanExceptionNoNumber) {

    if (this->_vector.size() < 2)
        throw Span::SpanExceptionNoNumber();
    
    std::sort(this->_vector.begin(), this->_vector.end());
    int longest = this->_vector[this->_vector.size() - 1] - this->_vector[0];

    return longest;
}

void Span::fillSpan(int nRandNumbers) throw (Span::SpanExceptionFull) {

    if(this->_vector.size() + nRandNumbers > this->_n)
        throw Span::SpanExceptionFull();
    
    srand(time(NULL));
    
    for (int i = 0; i < nRandNumbers; i++)
        this->_vector.push_back(rand());
}

std::vector<int> Span::getVector(void) const {

    return this->_vector;
}

const char* Span::SpanExceptionFull::what() const throw() {

    return "SpanException: vector full";
}

const char* Span::SpanExceptionNoNumber::what() const throw() {

    return "SpanException: only one or no number in the vector";
}

std::ostream &operator<<(std::ostream &out, Span &span) {

    if(span.getVector().size() == 0) {
        std::cout << "Span is empty";
        return out;
    }
    std::cout << "Span numbers: { ";
    for (unsigned int i = 0; i < span.getVector().size(); i++) {
        std::cout << span.getVector()[i];
        if (i < span.getVector().size() - 1)
            std::cout << ", ";
        else
            std::cout << " }";
    }
    return out;
}