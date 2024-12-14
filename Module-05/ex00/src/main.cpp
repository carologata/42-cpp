#include "../include/Bureaucrat.hpp"

int main(void) {
    
    printlnBlue("*** Bureaucrat1: Default constructor ***");
    Bureaucrat bureaucrat1;
    printlnBlue("name:");
    println(bureaucrat1.getName());
    printlnBlue("grade:");
    println(bureaucrat1.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Bureaucrat2: Parametrized constructor ***");
    Bureaucrat bureaucrat2("Bureaucrat2", 148);
    printlnBlue("name:");
    println(bureaucrat2.getName());
    printlnBlue("grade:");
    println(bureaucrat2.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Bureaucrat3: Parametrized constructor ***");
    Bureaucrat bureaucrat3("Bureaucrat3", 2);
    printlnBlue("name:");
    println(bureaucrat3.getName());
    printlnBlue("grade:");
    println(bureaucrat3.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Bureaucrat4: Copy constructor ***");
    Bureaucrat bureaucrat4(bureaucrat3);
    printlnBlue("name:");
    println(bureaucrat4.getName());
    printlnBlue("grade:");
    println(bureaucrat4.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Bureaucrat5: Parametrized constructor ***");
    Bureaucrat bureaucrat5("Bureaucrat5", 150);
    printlnBlue("*** Bureaucrat5: Assignment operator ***");
    bureaucrat5 = bureaucrat4; 
    printlnBlue("name:"); // The name will not be update, it is const
    println(bureaucrat5.getName());
    printlnBlue("grade:");
    println(bureaucrat5.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Burecraut4 ***");
    printlnBlue("grade:");
    println(bureaucrat4.getGrade());
    printlnBlue("Increment Burecraut4");
    bureaucrat4.increment();
    printlnBlue("grade:");
    println(bureaucrat4.getGrade());
    printlnBlue("Increment Burecraut4");
    bureaucrat4.increment();
    printlnBlue("grade:");
    println(bureaucrat4.getGrade());
    printlnBlue("***\n");

    printlnBlue("*** Burecraut2 ***");
    printlnBlue("grade:");
    println(bureaucrat2.getGrade());
    printlnBlue("Decrement Burecraut2");
    bureaucrat2.decrement();
    printlnBlue("grade:");
    println(bureaucrat2.getGrade());
    printlnBlue("Decrement Burecraut2");
    bureaucrat2.decrement();
    printlnBlue("grade:");
    println(bureaucrat2.getGrade());
    printlnBlue("Decrement Burecraut2");
    bureaucrat2.decrement();
    printlnBlue("grade:");
    println(bureaucrat2.getGrade());
    printlnBlue("***\n");

}