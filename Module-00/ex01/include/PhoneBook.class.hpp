#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ios>

class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);

    void add(void);
    void search(void) const;
    void exit(void) const;

    void printContactsList(void) const;
    void printSpecificContact(int index) const;

private:

    Contact contacts[8];
    int contactsQty;

};

#endif