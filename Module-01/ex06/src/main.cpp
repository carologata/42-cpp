#include "Harl.hpp"

int main(int argc, char *argv[]) {

    if(argc != 2) {
        std::cerr << "Invalid parameter." << std::endl;
        std::cerr << "Please, write one of these four levels:" << std::endl;
        std::cerr << "DEGUG | INFO | WARNING | ERROR" << std::endl; 

        return (1);
    }

    std::string parameter = argv[1];

    Harl complainer;

    complainer.filterComplain(parameter);

    return (0);
}
