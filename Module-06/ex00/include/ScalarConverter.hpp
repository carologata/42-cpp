#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <climits>
#include <limits>

class ScalarConverter {
    
public:
    
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
    ~ScalarConverter();

    static void convert(std::string parameter);
};

#endif