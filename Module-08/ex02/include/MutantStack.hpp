#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

    MutantStack() : std::stack<T, Container>() {};
    MutantStack(MutantStack const& copy) : std::stack<T, Container>(copy) {};
    MutantStack& operator=(MutantStack const& copy) {
        
        if (this != &copy)
            std::stack<T, Container>::operator=(copy);
        return *this;
    };
    ~MutantStack() {};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator               begin()          { return this->c.begin(); };
    iterator               end()            { return this->c.end(); };
    const_iterator         begin() const    { return this->c.begin(); };
    const_iterator         end() const      { return this->c.end(); };
    
    reverse_iterator       rbegin()         { return this->c.rbegin(); };
    reverse_iterator       rend()           { return this->c.rend(); };
    const_reverse_iterator rbegin() const   { return this->c.rbegin(); };
    const_reverse_iterator rend() const     { return this->c.rend(); };
    
};

#endif

/* In the context of std::stack, c is a protected member of the std::stack class that 
represents the underlying container. The std::stack class is a container adaptor that 
provides a stack interface, but it uses another container (by default, std::deque) 
to store the elements. The underlying container is accessible via the protected member c. */