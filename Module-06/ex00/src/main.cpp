#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv) {
    
    if(argc == 2) {

        if(argv[1][0] == '\0') {
            std::cout << "Error: invalid input." << std::endl;
            return (1);
        }
        ScalarConverter::convert(argv[1]);
        return (0);
    }
    else {
        std::cout << "Error: invalid number of arguments." << std::endl;
        return (1);
    }
}

/* #!/bin/bash

echo "Test for General"
./convert # invalid number of arguments.
echo "***"
./convert hey hi # invalid number of arguments.
echo "***"
./convert "" # invalid input.
echo "***"
./convert "Hello, World!"; # type conversion is impossible.
echo "***"
./convert "42a"; # type conversion is impossible.
echo "***"
./convert "42.42fa"; # type conversion is impossible.
echo "***"
./convert "42.42a"; # type conversion is impossible.
echo "***"
./convert "\a"; # Impossible
echo "***"
echo ""

echo "Test for Char"
./convert " "; # ' '
echo "***"
./convert "a"; # 'a'
echo "***"
./convert "7"; # Non displayable
echo "***"
./convert "43"; # '+'
echo "***"
./convert "128"; # Impossible
echo "***"
echo ""

echo "Test for Int"
./convert "42"; # 42
echo "***"
./convert "2147483647"; # 2147483647
echo "***"
./convert "2147483648"; # Impossible
echo "***"
./convert "-42"; # -42
echo "***"
./convert "-2147483648"; # -2147483648
echo "***"
./convert "-2147483649"; # Impossible
echo "***"
./convert "a"; # 97
echo "***"
echo ""

echo "Test for Float and Double"
./convert "42"; # 42.0f
echo "***"
./convert "42f"; # 42.0f
echo "***"
./convert "42.42f"; # 42.42f
echo "***"
./convert "a"; # 97.0f
echo "***"
./convert "-42"; # -42.0f
echo "***"
./convert "-42.42"; # -42.42f
echo "***"
./convert "+inff"; # +inff
echo "***"
./convert "-inff"; # -inff
echo "***"
./convert "+inf"; # +inf
echo "***"
./convert "-inf"; # -inf
echo "***"
./convert "nan"; # impossible, nanf and nan
echo "***"
./convert "nanf"; # impossible, nanf and nan
echo "***" */