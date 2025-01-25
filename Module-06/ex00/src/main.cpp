#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv) {
    


    return (0);
}


/*     //Tests
    printlnBlue("Test for General");
    ScalarConverter::convert("Hello, World!"); // type conversion is impossible.
    printlnBlue("*** ***");
    ScalarConverter::convert(""); // type conversion is impossible.
    printlnBlue("*** ***");
    ScalarConverter::convert("42a"); // type conversion is impossible.
    printlnBlue("*** ***");
    ScalarConverter::convert("42.42fa"); // type conversion is impossible.
    printlnBlue("*** ***");
    ScalarConverter::convert("42.42a"); // type conversion is impossible.
    printlnBlue("*** ***");
    ScalarConverter::convert("nan"); // impossible, nanf and nan
    printlnBlue("");

    printlnBlue("Test for Char");
    ScalarConverter::convert("a"); // 'a'
    printlnBlue("*** ***");
    ScalarConverter::convert("\a"); // Non displayable
    printlnBlue("*** ***");
    ScalarConverter::convert("7"); // Non displayable
    printlnBlue("*** ***");
    ScalarConverter::convert("43"); // '+'
    printlnBlue("*** ***");
    ScalarConverter::convert("128"); // Impossible
    printlnBlue("*** ***");
    printlnBlue("");

    printlnBlue("Test for Int");
    ScalarConverter::convert("42"); // 42
    printlnBlue("*** ***");
    ScalarConverter::convert("2147483647"); // 2147483647
    printlnBlue("*** ***");
    ScalarConverter::convert("2147483648"); // Impossible
    printlnBlue("*** ***");
    ScalarConverter::convert("-42"); // -42
    printlnBlue("*** ***");
    ScalarConverter::convert("-2147483648"); // -2147483648
    printlnBlue("*** ***");
    ScalarConverter::convert("-2147483649"); // Impossible
    printlnBlue("*** ***");
    ScalarConverter::convert("a"); // 97
    printlnBlue("*** ***");
    printlnBlue("");

    printlnBlue("Test for Float");
    ScalarConverter::convert("42"); // 42.0f
    printlnBlue("*** ***");
    ScalarConverter::convert("42f"); // 42.0f
    printlnBlue("*** ***");
    ScalarConverter::convert("42.42f"); // 42.42f
    printlnBlue("*** ***");
    ScalarConverter::convert("a"); // 97.0f
    printlnBlue("*** ***");
    ScalarConverter::convert("\a"); // 7.0f
    printlnBlue("*** ***");
    ScalarConverter::convert("-42"); // -42.0f
    printlnBlue("*** ***");
    ScalarConverter::convert("-42.42"); // -42.42f
    printlnBlue("*** ***");
    ScalarConverter::convert("+inff"); // +inff
    printlnBlue("*** ***");
    ScalarConverter::convert("-inff"); // -inff
    printlnBlue("*** ***");
    printlnBlue("");

    printlnBlue("Test for Double");
    ScalarConverter::convert("+inf"); // +inf
    printlnBlue("*** ***");
    ScalarConverter::convert("-inf"); // -inff
    printlnBlue("*** ***"); */