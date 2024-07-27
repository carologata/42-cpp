#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>
#include <string>

class Contact {

private:

    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:

    Contact(void);
    ~Contact(void);

    std::string getFirstName(void) const;
    void setFirstName(std::string firstName);

    std::string getLastName(void) const;
    void setLastName(std::string lastName);

    std::string getNickName(void) const;
    void setNickName(std::string nickName);

    std::string getPhoneNumber(void) const;
    void setPhoneNumber(std::string phoneNumber);

    std::string getDarkestSecret(void) const;
    void setDarkestSecret(std::string darkestSecret);
    
};

#endif