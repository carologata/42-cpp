#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>

class PmergeMe {

public:

    PmergeMe(void);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe(void);

    void mergeInsertSortVector(std::vector<int>& vec);
    void mergeInsertSortDeque(std::deque<int>& deque);

    static int compareCounter;

private:

    template <typename Container, typename Sequence>
    void mergeInsertionSort(Container& container, int pairSize);

    template <typename Container, typename Sequence>
    void createPairs(Container& container, int pairSize);

    template <typename Container, typename Sequence>
    void initializeMainAndPend(Container& container, Sequence& main, Sequence& pend, int numOfGroups); 

    template <typename Container, typename Sequence>
    size_t jacobsthalInsertion(Sequence& main, Sequence& pend);

    template <typename Container, typename Sequence>
    void insertLeftOverElem(Container& container, Sequence& main, Sequence& pend, int numOfGroups, size_t pendElemInserted);

    template <typename Container, typename Sequence>
    void updateSortedContainer(Container& container, Sequence& main, int pairSize);

    std::size_t getJacobsthalNum(std::size_t index);

    static std::size_t _jacobsthalNumbers[62];

};

template <typename Iterator>
void swapPairs(Iterator firstPairEndPos, int pairSize);

template <typename Iterator>
Iterator getPairMovePos(Iterator it, int moves);

template <typename Iterator>
bool isOrdered(Iterator first, Iterator second);

#endif