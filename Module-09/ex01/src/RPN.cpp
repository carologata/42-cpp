#include "../include/RPN.hpp"

RPN::RPN(void) : _nums() {}

RPN::RPN(std::stack<int> nums) : _nums(nums) {}

RPN::RPN(RPN const& copy) : _nums(copy._nums) {}

RPN& RPN::operator=(RPN const &copy) {
    if (this != &copy) {
        _nums = copy._nums;
    }
    return *this;
}

RPN::~RPN(void) {}

void RPN::validateRPN(std::string expression) {
    
    std::string token;
    std::istringstream iss(expression);
    int count = 0;

    while(iss >> token) {

        if(token == "+" || token == "-" || token == "/" || token == "*" ) {
            count--;
        }
        else if(isdigit(token.c_str()[0]) && token.length() == 1) {
            count++;
        }
        else {
            throw std::invalid_argument("Error");
        }
    }
    if(count != 1) {
        throw std::invalid_argument("Error");
    }
}

int RPN::calculateRPN(std::string expression) {

    std::string token;
    std::istringstream iss(expression);
    int x;
    int y;
    int z;

    while(iss >> token) {
        
        if(token == "+" || token == "-" || token == "/" || token == "*" ) {
            
            y = _nums.top();
            _nums.pop();
            x = _nums.top();
            _nums.pop();

            if(token == "+")
                z = x + y;
            else if(token == "-")
                z = x - y;
            else if(token == "/")
                z = x / y;
            else 
                z = x * y;
                
            _nums.push(z);                
        }
        else {
            _nums.push(atoi(token.c_str()));
        }
    }

    return z;
}