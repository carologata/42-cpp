#include "Contact.class.hpp"

Contact::Contact(void) {

    _firstName = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";

    return ;
}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const {
    return this->_firstName;
}

void Contact::setFirstName(std::string firstName) {
    if(!firstName.empty())
        this->_firstName = firstName;
}

std::string Contact::getLastName(void) const {
    return this->_lastName;
}

void Contact::setLastName(std::string lastName) {
    if(!lastName.empty())
        this->_lastName = lastName;
}

std::string Contact::getNickName(void) const {
    return this->_nickName;
}

void Contact::setNickName(std::string nickName) {
    if(!nickName.empty())
        this->_nickName = nickName;
}

std::string Contact::getPhoneNumber(void) const {
    return this->_phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    if(!phoneNumber.empty())
        this->_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
    return this->_darkestSecret;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    if(!darkestSecret.empty())
        this->_darkestSecret = darkestSecret;
}
