#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

#include <cstdio>
int main(void)
{
    PhoneBook bookList;
    std::string command;

    while(1) 
    {
        std::cout << "Enter one of three commands (ADD, SEARCH or EXIT): ";
        std::cin >> command;
        std::cout << std::endl;

        if(command == "ADD")
            bookList.add();
    }

}