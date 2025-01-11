#include "../include/Form.hpp"

int main(void) {

    printlnBlue("*** Form1 grade higher than 1 ***");
    try {
        Form form1("Form1", -5, 10);
        std::cout << form1 << std::endl;
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("***\n");

    printlnBlue("*** Form2 grade lower than 150 ***");
    try {
        Form form2("Form2", 5, 151);
        std::cout << form2 << std::endl;
    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("***\n");

    printlnBlue("*** Form3 ***");
    try {
        Form form3("Form3", 5, 10);
        std::cout << form3 << std::endl;

        printlnBlue("Bureaucrat1 tries to sign Form3");
        try {
            Bureaucrat bureaucrat1("Bureaucra1t", 12);
            std::cout << bureaucrat1 << std::endl;
            bureaucrat1.signForm(form3);
        } catch (std::exception &e) {
            println(e.what());
        }

        printlnBlue("Bureaucrat2 tries to sign Form3");
        try {
            Bureaucrat bureaucrat2("Bureaucrat2", 5);
            std::cout << bureaucrat2 << std::endl;
            bureaucrat2.signForm(form3);
        } catch (std::exception &e) {
            println(e.what());
        }

        // More than 1 bureaucrat can sign the same form
        printlnBlue("Bureaucrat3 tries to sign Form3");
        try {
            Bureaucrat bureaucrat3("Bureaucrat3", 1);
            std::cout << bureaucrat3 << std::endl;
            bureaucrat3.signForm(form3);
        } catch (std::exception &e) {
            println(e.what());
        }

    } catch (std::exception &e) {
        println(e.what());
    }
    printlnBlue("***\n");

    return (0);
}