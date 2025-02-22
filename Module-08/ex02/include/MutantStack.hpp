#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

    MutantStack() : std::stack<T, Container>() {};
    MutantStack(MutantStack const& copy) : std::stack<T, Container>(copy) {};
    MutantStack& operator=(MutantStack const& copy) {
        
        if (this != &copy)
            std::stack<T, Container>::operator=(copy);
        return (*this);
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

/* this syntax to define the std::stack:
template <class Type, class Container = deque<Type> > class stack;
Type – is the Type of element contained in the std::stack. It can be any valid C++ type or even a user-defined type.
Container – is the Type of underlying container object.

Member Types:
value_type - The first template parameter, T. It denotes the element types.
container_type - The second template parameter, Container. It denotes the underlying container type.
size_type - Unsigned integral type.

The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1)  */


/* In C++, vector is a dynamic array with the ability to resize itself automatically when an element 
is inserted or deleted. It is the part Standard Template Library (STL) and provide various useful 
functions for data manipulation. */

/* Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. 
They are similar to vectors, but are more efficient in case of insertion and deletion of elements. 
Unlike vectors, contiguous storage allocation may not be guaranteed. 
Double Ended Queues are basically an implementation of the data structure double-ended queue. 
A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in 
real life, wherein people are removed from the front and added at the back. Double-ended queues are a special 
case of queues where insertion and deletion operations are possible at both the ends.
The functions for deque are same as vector, with an addition of push and pop operations for both front and back. */  

/* Lists are sequence containers that allow non-contiguous memory allocation. As compared to the vector, the 
list has slow traversal, but once a position has been found, insertion and deletion are quick (constant time). 
Normally, when we say a List, we talk about a doubly linked list. For implementing a singly linked list, 
we use a forward_list. */