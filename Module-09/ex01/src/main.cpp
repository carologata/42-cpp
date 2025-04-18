#include "../include/RPN.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    RPN rpn;
    std::string expression = argv[1];
    int result;

    try {
        rpn.validateRPN(expression);
        result = rpn.calculateRPN(expression);
        std::cout << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}