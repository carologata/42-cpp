#include "Replace.hpp"

Replace::Replace(std::string filename, std::string strToSearch, std::string strToReplace) {

    _filename      = filename;
    _strToSearch   = strToSearch;
    _strToReplace  = strToReplace;
}

Replace::~Replace(void) {}

bool Replace::checkEmptyInput() {

    if(_filename.empty() || _strToSearch.empty() || _strToReplace.empty())
    {
        std::cout << "Error: empty input." << std::endl;
        return (1);
    }
    return (0);       
}

void Replace::replaceStrings() {

    if(checkEmptyInput())
        return ;
    std::ifstream ifs(_filename.c_str());
    if(!ifs)
    {
        std::cout << "Error: can not open the file " << _filename << std::endl;
        return ;
    }    
    std::string line, content;
    while(std::getline(ifs, line))
        content += line + '\n';
    ifs.close();
    size_t pos = 0;
    while((pos = content.find(_strToSearch, pos)) != std::string::npos)
    {
        content.erase(pos, _strToSearch.length());
        content.insert(pos, _strToReplace);
        pos += _strToReplace.length();
    }
    std::string outFilename = _filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if(!ofs)
    {
        std::cout << "Error: can not open the file " << outFilename << std::endl;
        return ;
    }
    ofs << content;
    ofs.close();
}