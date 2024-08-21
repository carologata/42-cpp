#ifndef REPLACE_H
#define REPLACE_H

#include <string>
#include <iostream>
#include <fstream>

class Replace {

public:

    Replace(std::string filename, std::string strToSearch, std::string strToReplace);
    ~Replace(void);

    void    replaceStrings();
    bool    checkEmptyInput();

private:

    std::string _filename;
    std::string _strToSearch;
    std::string _strToReplace;

};

#endif