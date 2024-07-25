#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iostream>

int main(void)
{
    PhoneBook bookList;
    Contact contact1;
    Contact contact2;
    Contact contact3;
    Contact contact4;
    Contact contact5;
    Contact contact6;
    Contact contact7;
    Contact contact8;
    Contact contact9;

    contact1.setPhone(988101422);
    contact1.setName("Caroline");
    bookList.addContact(contact1);

    contact2.setPhone(988101422);
    contact2.setName("Luciana");
    bookList.addContact(contact2);

    contact3.setPhone(988101422);
    contact3.setName("Rodrigo");
    bookList.addContact(contact3);

    contact4.setPhone(988101422);
    contact4.setName("Marta");
    bookList.addContact(contact4);

    contact5.setPhone(988101422);
    contact5.setName("Lucas");
    bookList.addContact(contact5);

    contact6.setPhone(988101422);
    contact6.setName("Ana");
    bookList.addContact(contact6);

    contact7.setPhone(988101422);
    contact7.setName("Paula");
    bookList.addContact(contact7);

    contact8.setPhone(988101422);
    contact8.setName("Carlos");
    bookList.addContact(contact8);

    contact9.setPhone(988101422);
    contact9.setName("Leo");
    bookList.addContact(contact9);

    bookList.listContacts();
}