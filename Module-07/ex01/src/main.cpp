#include "../include/iter.hpp"

#include <iostream>
#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

void sumOne(int &num){
    
    num += 1;
};

void replaceAWithE(char &c){ 
    if(c == 'a')
        c = 'e';
    else if(c == 'A')
        c = 'E';
};

template <typename T>
void printElement(T &element){
    std::cout << element << " ";
};

int main(void) {

    printlnBlue("Testing with int array:");
    int arrayInt[] = {1, 2, 3, 4, 5};
    int length = 5;
    printlnBlue("Before:");
    for(int i = 0; i < length; i++){
        std::cout << arrayInt[i] << " ";
    }
    std::cout << std::endl;
    iter(arrayInt, length, sumOne);
    printlnBlue("After:");
    for(int i = 0; i < length; i++){
        std::cout << arrayInt[i] << " ";
    }
    std::cout << std::endl;

    printlnBlue("Testing with char array:");
    char arrayChar[] = {'a', 'b', 'c', 'd', 'e', 'A', 'B', 'C', 'D', 'E'};
    length = 10;
    printlnBlue("Before:");
    for(int i = 0; i < length; i++){
        std::cout << arrayChar[i] << " ";
    }
    std::cout << std::endl;
    iter(arrayChar, length, replaceAWithE);
    printlnBlue("After:");
    for(int i = 0; i < length; i++){
        std::cout << arrayChar[i] << " ";
    }
    std::cout << std::endl;

    printlnBlue("Testing with int array and template function:");
    length = 5;
    iter(arrayInt, length, printElement);
    std::cout << std::endl;

    printlnBlue("Testing with char array and template function:");
    length = 10;
    iter(arrayChar, length, printElement);
    std::cout << std::endl;
}

