#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(void)
{
    PhoneBook bookList;
    std::string command;

    while(1) 
    {
        std::cout << "Enter one of three commands (ADD, SEARCH or EXIT): ";
        getline(std::cin, command);

        if(command == "ADD")
            bookList.add();
        else if(command == "SEARCH")
            bookList.search();
        else if(command == "EXIT")
            break;
        else 
            std::cout << "Invalid command. Please, write it again." << std::endl;
    }
    return (0);
}