#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdlib>

class PhoneBook {

private:

    Contact contacts[8];

public:

    int contactsQty;
    
    PhoneBook(void);
    ~PhoneBook(void);

    void add(void);
    void search(void) const;
    void exit(void) const;

    void printContactsList(void) const;
    void printSpecificContact(int index) const;

};

#endif