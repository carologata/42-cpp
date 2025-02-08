#include "../include/Array.hpp"
#include "../include/Array.tpp"

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

int main(void) {

    printlnBlue("*** Creating Default Array of Integer***");
    Array<int> array1;
    std::cout << "Size: " << array1.size() << std::endl;
    try {
        std::cout << "array1[0]: " << array1[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Creating Default Array of Char: ***");
    Array<char> array2;
    std::cout << "Size: " << array2.size() << std::endl;
    try {
        std::cout << "array2[0]: " << array2[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Creating Array of Integers Size 5: ***");
    Array<int> array3(5);
    std::cout << "Size: " << array3.size() << std::endl;
    printlnBlue("Trying to access with [] operator WITHOUT setting values: ");
    try {
        std::cout << "array3[0]: " << array3[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Setting values and accessing them with [] operator: ");
    for (int i = 0; i < array3.size(); i++) {
        array3[i] = i;
        std::cout << "array3[" << i << "]: " << array3[i] << std::endl;
    }
    printlnBlue("*** Trying to access an invalid index ***");
    try {
        std::cout << "array3[5]: " << array3[5] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Creating Array of Chars Size 7: ***");
    Array<char> array4(7);
    std::cout << "Size: " << array4.size() << std::endl;
    printlnBlue("Trying to access with [] operator WITHOUT setting values: ");
    try {
        std::cout << "array4[0]: " << array4[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("Setting values e accessing them with [] operator: ");
    for (int i = 0; i < array4.size(); i++) {
        array4[i] = 'A' + i;
        std::cout << "array4[" << i << "]: " << array4[i] << std::endl;
    }
    printlnBlue("*** Trying to access an invalid index ***");
    try {
        std::cout << "array4[7]: " << array4[7] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Copy Constructor: Instatiating array5 copying from array3 ***");
    Array<int> array5(array3);
    std::cout << "Size: " << array5.size() << std::endl;
    for (int i = 0; i < array5.size(); i++) {
        std::cout << "array3[" << i << "]: " << array3[i] << std::endl;
        std::cout << "array5[" << i << "]: " << array5[i] << std::endl;
    }
    printlnBlue("Changing the value on array3[1] should not change the value on array5[1]: ");
    array3[1] = 100;
    std::cout << "array3[1]: " << array3[1] << std::endl;
    std::cout << "array5[1]: " << array5[1] << std::endl;
    printlnBlue("*** ***\n");

    printlnBlue("*** Creating Array of Chars with Size 7 and Other with Size 5 ***");
    Array<char> array6(7);
    Array<char> array7(5);
    std::cout << "Size of array6: " << array6.size() << std::endl;
    std::cout << "Size of array7: " << array7.size() << std::endl;
    printlnBlue("Setting values e accessing them with [] operator: ");
    for (int i = 0; i < array6.size(); i++) {
        array6[i] = 'a' + i;
        std::cout << "array6[" << i << "]: " << array6[i] << std::endl;
    }
    for (int i = 0; i < array7.size(); i++) {
        array7[i] = 'A' + i;
        std::cout << "array7[" << i << "]: " << array7[i] << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Trying Operator Assignment: Assigning array6 Size 7 to array7 Size 5 ***");
    printlnBlue("Before assignment: ");
    for(int i = 0; i < array7.size(); i++) {
        std::cout << "array7[" << i << "]: " << array7[i] << std::endl;
    }
    printlnBlue("After assignment: ");
    try {
        array7 = array6;
        for(int i = 0; i < array7.size(); i++) {
            std::cout << "array7[" << i << "]: " << array7[i] << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Trying Operator Assignment: Assigning array6 Size 7 to array4 Size 7 ***");
    printlnBlue("Before assignment: ");
    for(int i = 0; i < array4.size(); i++) {
        std::cout << "array4[" << i << "]: " << array4[i] << std::endl;
    }
    printlnBlue("After assignment: ");
    try {
        array4 = array6;
        for(int i = 0; i < array4.size(); i++) {
            std::cout << "array4[" << i << "]: " << array4[i] << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");

    printlnBlue("*** Trying Operator Assignment: Assigning array6 Size 7 to array2 Size 0 ***");
    printlnBlue("Before assignment: ");
    for(int i = 0; i < array2.size(); i++) {
        std::cout << "array2[" << i << "]: " << array2[i] << std::endl;
    }
    printlnBlue("After assignment: ");
    try {
        array2 = array6;
        for(int i = 0; i < array2.size(); i++) {
            std::cout << "array2[" << i << "]: " << array2[i] << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printlnBlue("*** ***\n");
}