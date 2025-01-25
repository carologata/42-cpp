#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>
#include <cerrno>
#include "SafeConverter.hpp"

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

class ScalarConverter {
    
public:
    
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
    ~ScalarConverter();

    static void convert(std::string parameter);
};

bool isChar(std::string parameter);
bool isInt(std::string parameter);
bool isFloat(std::string parameter);
bool isDouble(std::string parameter);

#endif