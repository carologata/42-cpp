#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>
#include <cstddef>

class PhoneBook {

private:

    int contactsQty;
    Contact contacts[8];

public:

    PhoneBook(void);
    ~PhoneBook(void);

    void add(void);
    void search(size_t index) const;
    void exit(void) const;

};

#endif