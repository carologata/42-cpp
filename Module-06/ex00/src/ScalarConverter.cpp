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

    bool    isConvertable         = false;
    double  firstConvertableValue = 0.0;

    if (isChar(parameter)) {
        isConvertable = true;
        firstConvertableValue = parameter[0];
        std::cout << "Type char detected." << std::endl;
    }
    else if(isInt(parameter)) {
        isConvertable = true;
        firstConvertableValue = atoi(parameter.c_str());
        std::cout << "Type int detected." << std::endl;
    }
    else if(isFloat(parameter)) {
        isConvertable = true;
        firstConvertableValue = strtof(parameter.c_str(), NULL);
        std::cout << "Type float detected." << std::endl;
    }
    else if(isDouble(parameter)) {
        isConvertable = true;
        firstConvertableValue = strtod(parameter.c_str(), NULL);
        std::cout << "Type double detected." << std::endl;
    }
    else {
        std::cout << "Error: type conversion is impossible." << std::endl;
        return;
    }

    if(isConvertable) {
        safeConverterChar(firstConvertableValue);
        safeConverterInt(firstConvertableValue);
        safeConverterFloat(firstConvertableValue);
        safeConverterDouble(firstConvertableValue);
    }
}

bool isChar(std::string parameter) {
    
    if (parameter.length() == 1 && !isdigit(parameter[0])) {
        return (true);
    }
    return (false);
}

bool isInt(std::string parameter) {

    char *end;
    long int result = strtol(parameter.c_str(), &end, 10);

    if(result > std::numeric_limits<int>::max()\
        || result < std::numeric_limits<int>::min() \
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

    strtod(parameter.c_str(), &end);

    if(errno == ERANGE \
        || end == parameter.c_str() \
        || *end != '\0') {
            return (false);
    }
    return (true);
}
