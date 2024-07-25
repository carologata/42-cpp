#include "PhoneBook.class.hpp"


PhoneBook::PhoneBook(void) {

    this->contactsNbr = 0;
    std::cout << "PhoneBook constructor called" << std::endl;
    return ;
}

PhoneBook::~PhoneBook(void) {
    
    std::cout << "PhoneBook destructor called" << std::endl;
    return ;
}


void PhoneBook::listContacts(void) {
    
    std::cout << "*Phone Book List*" << std::endl;

    for(size_t i = 0; i < this->contactsNbr; i++)
    {
        std::cout << this->contacts[i].getName() << std::endl;
        std::cout << this->contacts[i].getPhone() << std::endl;
    }
}

void PhoneBook::addContact(Contact contact) {

    if(this->contactsNbr < 8)
    {
        if(!contact.getName().empty() && contact.getPhone() > 0)
            this->contacts[this->contactsNbr] = contact;

        std::cout << "Contact " << this->contactsNbr + 1 << " added to the list" << std::endl;
        std::cout << "Contact " << this->contactsNbr + 1 << " name: " << this->contacts[this->contactsNbr].getName() << std::endl;
        std::cout << "Contact " << this->contactsNbr + 1 << " phone: " << this->contacts[this->contactsNbr].getPhone() << std::endl; 

        this->contactsNbr++;
    } 
    else if(!contact.getName().empty() && contact.getPhone() > 0)
    {
        this->contacts[this->contactsNbr - 1] = contact;

        std::cout << "Contact replaced the last contact in the list" << std::endl;
        std::cout << "Contact " << this->contactsNbr << " name: " << this->contacts[this->contactsNbr - 1].getName() << std::endl;
        std::cout << "Contact " << this->contactsNbr << " phone: " << this->contacts[this->contactsNbr - 1].getPhone() << std::endl; 
    }
    return ;
}