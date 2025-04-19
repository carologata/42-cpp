#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>
#include <map>

typedef std::map<std::string, float> db;

class BitcoinExchange {

public:
    BitcoinExchange();
    BitcoinExchange(db dataBase);
    BitcoinExchange(BitcoinExchange const& copy);
    BitcoinExchange& operator=(BitcoinExchange const &copy);
    ~BitcoinExchange();

    void    setDataBase(std::string filename);
    void    setDataFile(std::string filename);

private:

    db       _dataBase;

    bool    validateFile(std::string& filename);
    bool    validateDate(std::string& date) const;
    bool    validateValue(float& value) const;
    void    exchange(std::string date, float value);
};

#endif


// In C++, associative containers are a type of container in the Standard Template Library (STL) 
// that store elements in a structured way, allowing efficient retrieval based on keys. 
// They use self-balancing binary search trees (like Red-Black Trees) or hash tables for quick lookups, 
// insertions, and deletions.

// 1. Ordered Associative Containers (Implemented as Red-Black Trees)
// These containers store elements in sorted order based on a comparison function (default: < operator).
// std::set – Stores unique elements in sorted order.
// std::map – Stores key-value pairs with unique keys in sorted order.
// std::multiset – Like set, but allows duplicate elements.
// std::multimap – Like map, but allows duplicate keys.

// 2. Unordered Associative Containers (Implemented as Hash Tables)
// These containers store elements in an unordered fashion using hashing, 
// which allows for average O(1) complexity for insert, find, and delete operations.
// std::unordered_set – Like set, but unordered.
// std::unordered_map – Like map, but unordered.
// std::unordered_multiset – Like multiset, but unordered.
// std::unordered_multimap – Like multimap, but unordered.