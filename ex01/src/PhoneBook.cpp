#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook(void) : contactsQty(0) {}

PhoneBook::~PhoneBook(void) {}

bool checkIfNbrIsValid(std::string input)
{
    if(input.empty())
        return (false);
    if(input.length() < 11 || input.length() > 12)
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
    bool isValid;
    std::string input;

    isValid = false;
    input = "";

    while(!isValid)
    {
        std::cout << output;
        std::cin >> input;
        std::cout << std::endl;

        if(isNbr)  
            isValid = checkIfNbrIsValid(input);
        else 
            isValid = checkIfStrIsValid(input);
        
        if(!isValid)
            std::cout << "Invalid input. Please, write it again.\n" << std::endl;
    }
    return (input);
}

void PhoneBook::add(void) {

    Contact contact;
    std::string input;

    input = readInput("First name: ", false);
    contact.setFirstName(input);

    input = readInput("Last name: ", false);
    contact.setLastName(input);
    
    input = readInput("Nick name: ", false);
    contact.setNickName(input);
    
    input = readInput("Phone name: (e.g. 41999999999): ", true);
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
}

