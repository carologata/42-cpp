#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {

public:
    RPN(void);
    RPN(std::stack<int> nums);
    RPN(RPN const &copy);
    RPN& operator=(RPN const &copy);
    ~RPN(void);

    void validateRPN(std::string expression);
    int calculateRPN(std::string expression);

private:
    
    std::stack<int> _nums;
};

#endif