#include "../include/Span.hpp"

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

int main(void) {

    printlnBlue("*** Subject tests ***");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    printlnBlue("*********************************");

    int shortest;
    int longest;

    printlnBlue("*** Default Span ***");
    Span span1;
    std::cout << span1 << std::endl;
    printlnBlue("Adding a number");
    try {
        span1.addNumber(1);
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Finding the shortest span");
    try {
        span1.shortestSpan();
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***");

    printlnBlue("*** Parametrized Span ***");
    Span span2(5);
    std::cout << span2 << std::endl;
    printlnBlue("Adding a number");
    try {
        span2.addNumber(12);
        std::cout << span2 << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Trying to fill with 6 numbers (greater than span size)");
    try {
        span2.fillSpan(6);
        std::cout << span2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Trying to fill with  numbers (less than span size)");
    try {
        span2.fillSpan(4);
        std::cout << span2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Finding the shortest span");
    try {
        shortest = span2.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Finding the longest span");
    try {
        longest = span2.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***");

    printlnBlue("*** Copy Span ***");
    Span span3(span2);
    std::cout << span3 << std::endl;
    printlnBlue("Adding a number");
    try {
        span3.addNumber(15);
        std::cout << span3 << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***");

    printlnBlue("*** Assignation Span ***");
    Span span4(5);
    span4.fillSpan(5);
    printlnBlue("Span 4 before assignation");
    std::cout << span4 << std::endl;
    printlnBlue("Span 3");
    std::cout << span3 << std::endl;
    span4 = span3;
    printlnBlue("Span 4 after assignation");
    std::cout << span4 << std::endl;
    printlnBlue("***");

    printlnBlue("*** Span with 10000 numbers ***");
    Span span5(10000);
    span5.fillSpan(10000);
    std::cout << span5 << std::endl;
    printlnBlue("Finding the shortest span");
    try {
        shortest = span5.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Finding the longest span");
    try {
        longest = span5.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***");

    return 0;
}