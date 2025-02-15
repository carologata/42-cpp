#include "../include/MutantStack.hpp"

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

int main()
{
    printlnBlue("*** Subject tests ***");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();   
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    printlnBlue("*** ***");

    return 0;
}