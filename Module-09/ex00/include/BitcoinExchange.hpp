#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, float> db;

class BitcoinExchange {

public:
    BitcoinExchange();
    BitcoinExchange(db dataBase, db dataFile);
    BitcoinExchange(BitcoinExchange const& copy);
    BitcoinExchange& operator=(BitcoinExchange const &copy);
    ~BitcoinExchange();

    void    set_dataBase(db dataBase);
    void    set_dataFile(db dataFile);

private:
    db _dataBase;
    db _dataFile;
};

#endif