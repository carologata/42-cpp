#include "Replace.hpp"

Replace::Replace(std::string filename, std::string strToSearch, std::string strToReplace) {

    this->filename      = filename;
    this->strToSearch   = strToSearch;
    this->strToReplace  = strToReplace;
}

Replace::~Replace(void) {}

void Replace::replaceStrings() {

    std::string line, content;

    if(strToSearch.empty() || strToReplace.empty())
    {
        std::cout << "Error: empty input." << std::endl;
    }            
    std::ifstream ifs(filename.c_str());
    if(!ifs)
    {
        std::cout << "Error: can not open the file " << filename << std::endl;
    }    
    
    while(std::getline(ifs, line))
        content += line + '\n';
    ifs.close();

    size_t pos = 0;
    while((pos = content.find(strToSearch, pos)) != std::string::npos)
    {
        content.erase(pos, strToSearch.length());
        content.insert(pos, strToReplace);
        pos += strToReplace.length();
    }

    std::string outFilename = filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if(!ofs)
    {
        std::cout << "Error: can not open the file " << outFilename << std::endl;
    }
    ofs << content;
    ofs.close();
}