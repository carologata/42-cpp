#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <cstddef>
#include <iostream>

class PhoneBook {

public:

    size_t contactsNbr;
    
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(Contact contact);
    void listContacts(void);

private:

    Contact contacts[8];

};

#endif