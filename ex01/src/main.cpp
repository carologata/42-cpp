#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(void)
{
    PhoneBook bookList;
    std::string command;

    while(1) 
    {
        std::cout << "Enter one of three commands: " << std::endl;
        std::cout << "1 - ADD" << std::endl;
        std::cout << "2 - SEARCH" << std::endl;;
        std::cout << "3 - EXIT" << std::endl;;
        getline(std::cin, command);

        if(command == "ADD" || command == "1")
            bookList.add();
        else if(command == "SEARCH" || command == "2")
            bookList.search();
        else if(command == "EXIT" || command == "3")
            break;
        else 
            std::cout << "Invalid command. Please, write it again." << std::endl;
    }
    return (0);
}