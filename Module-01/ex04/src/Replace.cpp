#include "Replace.hpp"

Replace::Replace(std::string filename, std::string strToSearch, std::string strToReplace) {

    this->filename      = filename;
    this->strToSearch   = strToSearch;
    this->strToReplace  = strToReplace;
}

Replace::~Replace(void) {}

bool Replace::validateInputs() {

    if(strToSearch.empty() || strToReplace.empty())
    {
        std::cout << "Error: empty input." << std::endl;
        return false;
    }            
    std::ifstream ifs(filename.c_str());
    if(!ifs)
    {
        std::cout << "Error: can not open the file " << filename << std::endl;
        return false;
    }    
    std::string outFilename = filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if(!ofs)
    {
        std::cout << "Error: can not open the file " << outFilename << std::endl;
        return false;
    }
    return true;
}

void Replace::replaceStrings() {

    
}