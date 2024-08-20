#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl {

public:

    Harl(void);
    ~Harl(void);
    
    void filterComplain(std::string level);

private:

    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    
    typedef void (Harl::*functionPtr)(void);
    
    functionPtr functions[4];
    std::string levels[4];

    enum level {
        DEBUG,
        INFO, 
        WARNING,
        ERROR
    };
};

#endif