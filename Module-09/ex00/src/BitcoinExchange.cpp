#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _dataBase() {}

BitcoinExchange::BitcoinExchange(db dataBase) : _dataBase(dataBase) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) : _dataBase(copy._dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &copy) {
    if (this != &copy) {
        _dataBase = copy._dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validateFile(std::string& filename) {

    size_t dotPos = filename.find_last_of(".");
    if (dotPos == std::string::npos || (filename.substr(dotPos) != ".csv" && filename.substr(dotPos) != ".txt") ) {
        std::cerr << "Error: Invalid extension." << std::endl;
        return false;
    }
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << "." << std::endl;
        return false;
    }
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Error: File is empty or unreadable." << std::endl;
        return false;
    }
    file.close();

    return true;
} 

bool BitcoinExchange::validateDate(std::string& date) const {

    std::istringstream ss(date);
    int  year, month, day;
    char delimiter1, delimiter2;
    bool isLeapYear;

    ss >> year >> delimiter1 >> month >> delimiter2 >> day;

	if(ss.fail() || delimiter1 != '-' || delimiter2 != '-' || day < 1 || month < 1 || month > 12 || year < 0) 
		return false;
    if(year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
        return false;
    if (month == 2) { 
        isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28))
            return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { 
        if (day > 30)
            return false;
    } else { 
        if (day > 31) 
            return false;
    }
    return true;
}

bool BitcoinExchange::validateValue(float& value) const{

    if(value < 0 || value > 1000) 
        return false;
    return true;
}

void BitcoinExchange::setDataBase(std::string filename) {

    std::string line;
    std::string date;
    std::string strValue;
    float floatValue;
    size_t dotPos;
    size_t newLinePos;
    
    if(!validateFile(filename))
        return ;
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << "." << std::endl;
        return;
    }
    std::getline(file, line);
    while (std::getline(file, line)) {
        dotPos = line.find(',');
        date = line.substr(0, dotPos);
        if(!validateDate(date)) {
            std::cerr << "Error: Invalid date." << std::endl;
            return ;
        }
        newLinePos = line.find('\n');
        strValue = line.substr(dotPos + 1, newLinePos);
        std::istringstream valueStream(strValue); 
        valueStream >> floatValue;
        if(!validateValue(floatValue)) {
            std::cerr << "Error: Invalid value." << std::endl;
            return ;
        }
        _dataBase[date] = floatValue;
    }
}

void BitcoinExchange::setDataFile(std::string filename) {

    std::string line;
    std::string date;
    std::string strValue;
    float floatValue;
    size_t pipePos;
    
    if(!validateFile(filename))
        return ;   
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << "." << std::endl;
        return ;
    }
    while (std::getline(file, line)) {
        pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: Missing '|' in line." << std::endl;
            continue;
        }
        if (pipePos == 0 || pipePos == line.length() - 1 || line[pipePos - 1] != ' ' || line[pipePos + 1] != ' ') {
            std::cout << "Error: Missing space before or after '|' in line." << std::endl;
            continue ;
        }
        date = line.substr(0, pipePos - 1);
        if (!validateDate(date)) {
            std::cout << "Error: Invalid date." << std::endl;
            continue ;
        }
        strValue = line.substr(pipePos + 2); 
        std::istringstream valueStream(strValue);
        valueStream >> floatValue;
        if(!validateValue(floatValue)) {
            std::cout << "Error: Invalid value." << std::endl;
            continue ;
        }
        exchange(date, floatValue);
    }
}

void BitcoinExchange::exchange(std::string date, float value) {

    float result;
    std::map<std::string, float>::iterator it;

    it = _dataBase.lower_bound(date);
    if (it == _dataBase.begin() && it->first != date) {
        std::cout << "Error: No valid exchange rate." << std::endl;
        return ;
    }
    if (it->first != date) 
        --it;
    result = it->second * value;
    std::cout << it->first << " => " << value << " = " << result << std::endl;
}