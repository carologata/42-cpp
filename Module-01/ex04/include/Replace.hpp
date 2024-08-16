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

private:

    std::string filename;
    std::string strToSearch;
    std::string strToReplace;

};

#endif