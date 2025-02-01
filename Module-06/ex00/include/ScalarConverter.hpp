#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>
#include <cerrno>
#include "SafeConverter.hpp"

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