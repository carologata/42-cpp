#include "Harl.hpp"

int main(void) {

    Harl complainer;

    std::cout << "*** DEBUG ***" << std::endl;
    complainer.complain("DEBUG");

    std::cout << "*** INFO ***" << std::endl;
    complainer.complain("INFO");

    std::cout << "*** WARNING ***" << std::endl;
    complainer.complain("WARNING");

    std::cout << "*** ERROR ***" << std::endl;
    complainer.complain("ERROR");

    std::cout << "*** NOT A VALID INPUT ***" << std::endl;
    complainer.complain("INVALID");
}