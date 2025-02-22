#include "../include/easyfind.hpp"
#include <iostream>

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;
#define printlnGreen(text) std::cout << "\033[1;32m" << text << "\033[0m" << std::endl;
#define printlnRed(text) std::cout << "\033[1;31m" << text << "\033[0m" << std::endl;

int main(void) {

    printlnBlue("*** Testing with int vector ***");
    {
        printlnBlue("Testing with int vector with valid occurance");
        
        int array[] = {10, 20, 30, 40, 50};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::vector<int> vec(array, array + array_size);

        try {
            printlnGreen(*(easyfind(vec, 30)));
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
        printlnBlue("Testing with int vector with valid occurance and in last position");
        try {
            printlnGreen(*(easyfind(vec, 50)));
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
        printlnBlue("Testing with int vector with valid invalid occurance");
        try {
            printlnGreen(*(easyfind(vec, 60)));
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
    }

    printlnBlue("*** Testing with char vector ***");
    {
        printlnBlue("Testing with char vector with valid occurance");

        char array[] = {'a', 'b', 'c', 'd', 'e'};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::vector<int> vec(array, array + array_size);

        try {
            printlnGreen(*(easyfind(vec, 'c'))); //shows the decimal
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
    }

    printlnBlue("*** Testing with int deque ***");
    {
        printlnBlue("Testing with int deque with valid occurance");

        int array[] = {0, 1, 2, 3, 4};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::deque<int> deq(array, array + array_size);

        std::deque<int>::iterator occurrance; 
        try {
            occurrance = easyfind(deq, 3);
            printlnGreen(*occurrance);
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
        printlnBlue("Testing with int deque with valid occurance and in last position");
        try {
            occurrance = easyfind(deq, 4);
            printlnGreen(*occurrance);
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
        printlnBlue("Testing with int deque with valid invalid occurance");
        try {
            occurrance = easyfind(deq, 5);
            printlnGreen(*occurrance);
            printlnGreen("Found!!!");
        }
        catch (std::exception &e) {
            printlnRed("Element not found.");
        }
    }

    return 0;  
}