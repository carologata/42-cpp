#include "../include/MutantStack.hpp"

#define printlnBlue(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

int main()
{
    printlnBlue("*** Subject Tests ***");
    MutantStack<int> mstack;
    mstack.push(5); // 5
    mstack.push(17); // 17 5
    std::cout << mstack.top() << std::endl;
    mstack.pop();  // 5 
    std::cout << mstack.size() << std::endl; 
    mstack.push(3); // 3 5
    mstack.push(5); // 5 3 5
    mstack.push(737); // 737 5 3 5
    //[...]
    mstack.push(0); // 0 737 5 3 5
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


    printlnBlue("*** Standard Deque ***");
    std::deque<int> sdeque;
    sdeque.push_front(5); // 5
    sdeque.push_front(17); // 17 5
    std::cout << sdeque.front() << std::endl;
    sdeque.pop_front();  // 5
    std::cout << sdeque.size() << std::endl;
    sdeque.push_front(3); // 3 5
    sdeque.push_front(5); // 5 3 5
    sdeque.push_front(737); // 737 5 3 5
    //[...]
    sdeque.push_front(0); // 0 737 5 3 5
    std::deque<int>::iterator it2 = sdeque.begin();
    std::deque<int>::iterator ite2 = sdeque.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    printlnBlue("*** ***");

    printlnBlue("*** MutantStack Vector ***");
    MutantStack<int, std::vector<int> > mstack2;
    mstack2.push(5); // 5
    mstack2.push(17); // 17 5
    std::cout << mstack2.top() << std::endl;
    mstack2.pop();  // 5
    std::cout << mstack2.size() << std::endl;
    mstack2.push(3); // 3 5
    mstack2.push(5); // 5 3 5
    mstack2.push(737); // 737 5 3 5
    //[...]
    mstack2.push(0); // 0 737 5 3 5
    MutantStack<int, std::vector<int> >::iterator it3 = mstack2.begin();
    MutantStack<int, std::vector<int> >::iterator ite3 = mstack2.end();
    ++it3;
    --it3;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::stack<int, std::vector<int> > s2(mstack2);
    printlnBlue("*** ***");

    printlnBlue("*** MutantStack List ***");
    MutantStack<int, std::list<int> > mstack3;
    mstack3.push(5); // 5
    mstack3.push(17); // 17 5
    std::cout << mstack3.top() << std::endl;
    mstack3.pop();  // 5
    std::cout << mstack3.size() << std::endl;
    mstack3.push(3); // 3 5
    mstack3.push(5); // 5 3 5
    mstack3.push(737); // 737 5 3 5
    //[...]
    mstack3.push(0); // 0 737 5 3 5
    MutantStack<int, std::list<int> >::iterator it4 = mstack3.begin();
    MutantStack<int, std::list<int> >::iterator ite4 = mstack3.end();
    ++it4;
    --it4;
    while (it4 != ite4)
    {
        std::cout << *it4 << std::endl;
        ++it4;
    }
    std::stack<int, std::list<int> > s3(mstack3);
    printlnBlue("*** ***");

    return 0;
}

/* 
The advantages of using different containers in a stack can be summarized as follows:

std::deque<T> (Default) → Balanced Performance: Fast push/pop, moderate iteration and memory usage.
std::vector<T> → Best for Iteration: Fastest traversal and random access, but slower insertions/removals.
std::list<T> → Best for Frequent Insertions/Deletions: Stable iterators and efficient modifications but higher memory overhead. */