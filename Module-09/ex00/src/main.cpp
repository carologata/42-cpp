#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: usage: ./btc [filename].csv or [filename].txt" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.setDataBase("data.csv");
    exchange.setDataFile(argv[1]);

    return (0);
}   