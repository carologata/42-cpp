#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook(void) : contactsQty(0) {}

PhoneBook::~PhoneBook(void) {}

bool checkIfNbrIsValid(std::string input)
{
    if(input.empty())
        return (false);
    if(input.length() < 10 || input.length() > 11)
        return (false);
    for(size_t i = 0; i < input.length(); i++)
    {
        if(!isdigit(input[i]))
            return (false);
    }
    return (true);
}

bool checkIfStrIsValid(std::string input)
{
    if(input.empty())
        return (false);
    return (true);
}

std::string readInput(std::string output, bool isNbr)
{
    bool isValid        = false;
    std::string input   = "";

    while(!isValid)
    {
        std::cout << output;
        std::getline(std::cin, input); 
        if(isNbr)  
            isValid = checkIfNbrIsValid(input);
        else 
            isValid = checkIfStrIsValid(input);
        
        if(!isValid)
            std::cout << "Invalid input. Please, write it again." << std::endl;
    }
    return (input);
}

void PhoneBook::add(void) {

    Contact     contact;
    std::string input;

    input = readInput("First name: ", false);
    contact.setFirstName(input);

    input = readInput("Last name: ", false);
    contact.setLastName(input);
    
    input = readInput("Nickname: ", false);
    contact.setNickName(input);
    
    input = readInput("Phone number: (e.g. 41999999999): ", true);
    contact.setPhoneNumber(input);
    
    input = readInput("Darkest secret: ", false);
    contact.setDarkestSecret(input);
    
    if(contactsQty < 8)
    {
        contacts[contactsQty] = contact;
        contactsQty++;
    }
    else
    {
        contacts[contactsQty - 1] = contact;
    }

    std::cout << "Contact added." << std::endl;
}

bool checkIfIndexIsValid(std::string input, int contactsQty) {

    int index = -1;

    if(input.length() != 1)
        return (false);
    if(input[0] < '0' || input[0] > '7')
        return (false);
    
    index = atoi(input.c_str());
    if(index >= 0 && index < contactsQty && index < 8)
        return (true);
    return (false);    
}

std::string truncate(std::string str)
{
    if(str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::printContactsList(void) const {

    std::cout << std::right << std::setw(10) << "Index";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < contactsQty && i < 8; i++)
    {
        std::cout << std::right << std::setw(10) << i;
        std::cout << std::right << " | ";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getFirstName());
        std::cout << std::right << " | ";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getLastName());
        std::cout << std::right << " | ";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::printSpecificContact(int index) const {

    std::cout << std::right << std::setw(10) << "Index";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

    std::cout << std::right << std::setw(10) << index;
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << truncate(contacts[index].getFirstName());
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << truncate(contacts[index].getLastName());
    std::cout << std::right << " | ";
    std::cout << std::right << std::setw(10) << truncate(contacts[index].getNickName()) << std::endl;  
}

void PhoneBook::search(void) const {

    int index;
    bool isValid      = false;
    std::string input = "";

    if(contactsQty == 0)
    {
        std::cout << "No contacts saved." << std::endl;
        return ;
    }
    printContactsList();

    while(!isValid)
    {
        std::cout << "Enter the index: ";
        std::getline(std::cin, input);

        isValid = checkIfIndexIsValid(input, contactsQty);
        if(isValid)
        {
            index = atoi(input.c_str());
            printSpecificContact(index);
        }
        else
        {
            std::cout << "Invalid index. Please, write it again." << std::endl;
        } 
    }
}