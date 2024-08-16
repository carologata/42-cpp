#include "Replace.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid number of inputs." << std::endl;
        return (1);
    }

    Replace replaceFile(argv[1], argv[2], argv[3]);

    replaceFile.replaceStrings();
}