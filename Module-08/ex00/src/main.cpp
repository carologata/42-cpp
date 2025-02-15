#include "../include/easyfind.hpp"
#include <iostream>

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

int main(void) {

    int occurrance;

    printlnBlue("*** Testing with int vector ***");
    {
        printlnBlue("Testing with int vector with valid occurance");
        
        int array[] = {1, 2, 3, 4, 5};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::vector<int> vec(array, array + array_size);

        try {
            occurrance = easyfind(vec, 3);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
        printlnBlue("Testing with int vector with valid occurance and in last position");
        try {
            occurrance = easyfind(vec, 5);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
        printlnBlue("Testing with int vector with valid invalid occurance");
        try {
            occurrance = easyfind(vec, 6);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
    }

    printlnBlue("*** Testing with char vector ***");
    {
        printlnBlue("Testing with char vector with valid occurance");

        char array[] = {'a', 'b', 'c', 'd', 'e'};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::vector<int> vec(array, array + array_size);

        try {
            occurrance = easyfind(vec, 'c');
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
    }

    printlnBlue("*** Testing with int deque ***");
    {
        printlnBlue("Testing with int deque with valid occurance");

        int array[] = {0, 1, 2, 3, 4};
        const size_t array_size = sizeof(array) / sizeof(array[0]);
        std::deque<int> deq(array, array + array_size);
        try {
            occurrance = easyfind(deq, 3);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
        printlnBlue("Testing with int deque with valid occurance and in last position");
        try {
            occurrance = easyfind(deq, 4);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
        printlnBlue("Testing with int deque with valid invalid occurance");
        try {
            occurrance = easyfind(deq, 5);
            std::cout << "Element found at index: " << occurrance << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Element not found." << std::endl;
        }
    }

    return 0;  
}