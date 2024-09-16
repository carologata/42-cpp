#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define IDEAS_NBR 100

class Brain {

public:

    Brain(void);
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    ~Brain(void);

    std::string     getIdea(int index) const;
    void            setIdea(int index, std::string idea);

private:
    
    std::string _ideas[IDEAS_NBR]; 
};

#endif