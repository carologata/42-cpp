#include "../include/SafeConverter.hpp"

/* Static Cast: This is the simplest type of cast that can be used. It is a compile-time cast. 
It does things like implicit conversions between types (such as int to float, or pointer to void*), 
and it can also call explicit conversion functions (or implicit ones). */

void safeConverterChar(double firstConvertableValue) {

    if(firstConvertableValue >= 0 && firstConvertableValue <= 127) {
        if(isprint(firstConvertableValue)) {
            std::cout << "char: '" << static_cast<char>(firstConvertableValue) << "'" << std::endl;
        }
        else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
}

void safeConverterInt(double firstConvertableValue) {
    
    if(firstConvertableValue >= std::numeric_limits<int>::min() && firstConvertableValue <= std::numeric_limits<int>::max()) {
            std::cout << "int: " << static_cast<int>(firstConvertableValue) << std::endl;
    }
    else {
        std::cout << "int: impossible" << std::endl;
    }
}

void safeConverterFloat(double firstConvertableValue) {
        
    if(firstConvertableValue >= -std::numeric_limits<float>::max() && firstConvertableValue <= std::numeric_limits<float>::max()) { 
        if (firstConvertableValue - static_cast<int>(firstConvertableValue) == 0) {
		    std::cout << "float: " << static_cast<float>(firstConvertableValue) << ".0f" << std::endl;
        }
        else {
            std::cout << "float: " << static_cast<float>(firstConvertableValue) << "f" << std::endl;
        }
    }
    else if(std::isinf(firstConvertableValue)) {
		std::cout << "float: " << (firstConvertableValue > 0 ? "+inff" : "-inff") << std::endl;
    }
    else {
        std::cout << "float: nanf" << std::endl;
    }
}

void safeConverterDouble(double firstConvertableValue) {
    
    if(firstConvertableValue >= -std::numeric_limits<double>::max() && firstConvertableValue <= std::numeric_limits<double>::max()) {
        if (firstConvertableValue - static_cast<int>(firstConvertableValue) == 0) {
            std::cout << "double: " << static_cast<double>(firstConvertableValue) << ".0" << std::endl;
        }
        else {
            std::cout << "double: " << static_cast<double>(firstConvertableValue) << std::endl;
        }
    }
    else if(std::isinf(firstConvertableValue)) {
		std::cout << "double: " << (firstConvertableValue > 0 ? "+inf" : "-inf") << std::endl;
    }
    else {
        std::cout << "double: nan" << std::endl;
    }   
}