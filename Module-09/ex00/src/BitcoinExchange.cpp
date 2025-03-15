#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _dataBase(), _dataFile() {}

BitcoinExchange::BitcoinExchange(db dataBase, db dataFile) : _dataBase(dataBase), _dataFile(dataFile) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) : _dataBase(copy._dataBase), _dataFile(copy._dataFile) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &copy) {
    if (this != &copy) {
        _dataBase = copy._dataBase;
        _dataFile = copy._dataFile;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::set_dataBase(db dataBase) {

    
}