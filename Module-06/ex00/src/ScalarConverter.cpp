#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    
    (void) copy;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string parameter) {
    
    
}

bool isChar(std::string parameter) {
    
    if (parameter.length() == 1 && isprint(parameter[0]) && !isdigit(parameter[0])) {
        return (true);
    }
    return (false);
}

bool isInt(std::string parameter) {

    char *end;
    long int result = std::strtol(parameter.c_str(), &end, 10);

    if(result > INT_MAX \
        || result < INT_MIN \
        || end == parameter.c_str() \
        || *end != '\0') {
            return (false);
    }
    return (true);
}

bool isFloat(std::string parameter) {   

    char *end;

    if (((parameter == "+inff") || (parameter == "-inff") || (parameter == "inff")) || (parameter == "nanf")) {
		return (true);
	}

    double result = strtod(parameter.c_str(), &end);

    if(result > std::numeric_limits<float>::max() \
        || result < -std::numeric_limits<float>::max() \
        || end == parameter.c_str() \
        || *end != 'f' \
        || *(end + 1) != '\0') {
            return (false);
    }
    return (true);
}

bool isDouble(std::string parameter) {
    
    char *end;
    errno = 0;

    if (((parameter == "+inf") || (parameter == "-inf") || (parameter == "inf")) || (parameter == "nan")) {
        return (true);
    }

    double result = strtod(parameter.c_str(), &end);

    if(errno == ERANGE \
        || end == parameter.c_str() \
        || *end != '\0') {
            return (false);
    }
    return (true);
}

