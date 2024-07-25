#include "Contact.class.hpp"

Contact::Contact(void) {

    this->_phone = 0;
    this->_name = "";
    std::cout << "Contact constructor called" << std::endl;
    return ;
}

Contact::~Contact(void) {

    std::cout << "Contact destructor called" << std::endl;
    return ;
}

size_t Contact::getPhone(void) const {
    return this->_phone;
}

void Contact::setPhone(size_t phone) {
    
    const size_t min = 99999999;
    const size_t max = 1000000000;

    if(phone > min && phone < max)
    {
        this->_phone = phone;
        std::cout << "Contact phone is set" << std::endl;
    }
    else
    {
        std::cout << "Contact phone could not be set" << std::endl;
    }

    return ;
}

std::string Contact::getName(void) const {
    return this->_name;
}

void Contact::setName(std::string name) {
    this->_name = name;
    std::cout << "Contact name is set" << std::endl;
}
