#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <cstddef>
#include <iostream>
#include <string>

class Contact {

public:

    Contact(void);
    ~Contact(void);

    size_t          getPhone(void) const;
    void            setPhone(size_t phone);

    std::string     getName(void) const;
    void            setName(std::string name);

private:

    std::string _name;
    size_t _phone;
    
};

#endif