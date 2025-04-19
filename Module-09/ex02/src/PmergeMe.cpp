#include "../include/PmergeMe.hpp"

int PmergeMe::compareCounter = 0;
std::size_t PmergeMe::_jacobsthalNumbers[62] = {0};

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &src) {     
    (void) src; 
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {  
    (void)copy;
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container, typename Sequence>
void PmergeMe::mergeInsertionSort(Container& container, int pairSize) {

    Sequence main;
    Sequence pend;
    std::size_t pendElemInserted;

    createPairs<Container, Sequence>(container, pairSize);    
    initializeMainAndPend<Container, Sequence>(container, main, pend, pairSize);
    pendElemInserted = jacobsthalInsertion<Container, Sequence>(main, pend);
    insertLeftOverElem<Container, Sequence>(container, main, pend, pairSize, pendElemInserted);
    updateSortedContainer<Container, Sequence>(container, main, pairSize);
}

template <typename Container, typename Sequence>
void PmergeMe::createPairs(Container& container, int pairSize) {
    
    typedef typename Container::iterator CIterator;

    int numOfGroups = container.size() / pairSize;
    if (numOfGroups < 2) {
        return;
    }

    int numPairToCompare = numOfGroups / 2;

    CIterator firstPairPos = container.begin();
    CIterator lastPairPos  = getPairMovePos(container.begin(), numPairToCompare * pairSize * 2);

    int move = 2 * pairSize;
    for (CIterator it = firstPairPos; it < lastPairPos; std::advance(it, move)) {
        CIterator firstPairEndPos  = getPairMovePos(it, pairSize - 1);
        CIterator secondPairEndPos = getPairMovePos(it, pairSize * 2 - 1); 
        if (!isOrdered(firstPairEndPos, secondPairEndPos)) {
            swapPairs(firstPairEndPos, pairSize);
        }
    }
    mergeInsertionSort<Container, Sequence>(container, pairSize * 2);
}

template <typename Container, typename Sequence>
void PmergeMe::initializeMainAndPend(Container& container, Sequence& main, Sequence& pend, int pairSize) {

    typedef typename Container::iterator CIterator;

    int numOfGroups = container.size() / pairSize;

    for (int i = 0; i < numOfGroups; i++) {
        CIterator lastPairPos  = getPairMovePos(container.begin(), (pairSize * i) + pairSize - 1);
        if (i == 0 || i % 2 == 1) {
            main.push_back(lastPairPos);
        } else {
            pend.push_back(lastPairPos);
        }
    }
}

template <typename Container, typename Sequence>
size_t PmergeMe::jacobsthalInsertion(Sequence& main, Sequence& pend) {

    typedef typename Container::iterator CIterator;
    typedef typename Sequence::iterator SIterator;
    SIterator pend_it;
    
    std::size_t pendElemInserted = 0;
    for (std::size_t jacobsthalIndex = 2; pendElemInserted < pend.size(); jacobsthalIndex++) {
        
        std::size_t jacobsthalNum = getJacobsthalNum(jacobsthalIndex);
        std::size_t pendElemToInsert = getJacobsthalNum(jacobsthalIndex) - getJacobsthalNum(jacobsthalIndex - 1);
        
        if (pendElemToInsert > pend.size() - pendElemInserted) {
            break;
        }

        int mainLimitPos = 0;
        pend_it = getPairMovePos(pend.begin() + pendElemInserted, (pendElemToInsert - 1));
        while (pendElemToInsert > 0) {
            SIterator limitInsertPos = getPairMovePos(main.begin(), getJacobsthalNum(jacobsthalIndex) + pendElemInserted - mainLimitPos);
            SIterator insertPos = std::upper_bound(main.begin(), limitInsertPos, *pend_it, isOrdered<CIterator>);
            SIterator insertedPos = main.insert(insertPos, *pend_it);

            if (std::distance(main.begin(), insertedPos) == static_cast<std::ptrdiff_t>(jacobsthalNum + pendElemInserted)) {
                mainLimitPos++;
            }

            std::advance(pend_it, -1);
            pendElemToInsert--;
            pendElemInserted++;
        }
    }
    return pendElemInserted;
}

template <typename Container, typename Sequence>
void PmergeMe::insertLeftOverElem(Container& container, Sequence& main, Sequence& pend, int pairSize, size_t pendElemInserted) {

    typedef typename Container::iterator CIterator;
    typedef typename Sequence::iterator SIterator;

    bool isOdd = (container.size() / pairSize) % 2 == 1 ? 1 : 0;

    for (size_t i = pendElemInserted; i < pend.size(); i++) {
        SIterator leftElem = getPairMovePos(pend.begin(), i);
        SIterator limitInsertPos = getPairMovePos(main.begin(), main.size() - pend.size() + i + isOdd);
        SIterator insertedPos = std::upper_bound(main.begin(), limitInsertPos, *leftElem, isOrdered<CIterator>);
        main.insert(insertedPos, *leftElem);
    }
}

template <typename Container, typename Sequence>
void PmergeMe::updateSortedContainer(Container& container, Sequence& main, int pairSize) {
    
    typedef typename Container::iterator CIterator;
    typedef typename Sequence::iterator SIterator;

    Container sortedContainer;
    for (SIterator it = main.begin(); it != main.end(); it++) {
        for (int groupPos = 0; groupPos < pairSize; groupPos++) {
            CIterator largestNumInGroupPos = *it;
            std::advance(largestNumInGroupPos, -pairSize + groupPos + 1);
            sortedContainer.push_back(*largestNumInGroupPos);
        }
    }
    std::copy(sortedContainer.begin(), sortedContainer.end(), container.begin());
}

std::size_t PmergeMe::getJacobsthalNum(std::size_t index) {

    if (std::size_t cache = _jacobsthalNumbers[index]) {
        return cache;
    }
    std::size_t result = round((pow(2, index + 1) + pow(-1, index)) / 3);
    _jacobsthalNumbers[index] = result;

    return result;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    
    compareCounter = 0;
    mergeInsertionSort<std::vector<int>, std::vector<std::vector<int>::iterator> >(vec, 1);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deque) {
    
    compareCounter = 0;
    mergeInsertionSort<std::deque<int>, std::deque<std::deque<int>::iterator> >(deque, 1);
}

template <typename Iterator>
void swapPairs(Iterator firstPairEndPos, int pairSize) {
    
    Iterator firstPairBeginPos  = getPairMovePos(firstPairEndPos, -pairSize + 1);
    Iterator secondPairBeginPos = getPairMovePos(firstPairBeginPos, pairSize);

    while (firstPairBeginPos != secondPairBeginPos) {
        std::iter_swap(firstPairBeginPos, getPairMovePos(firstPairBeginPos, pairSize));
        firstPairBeginPos++;
    }
}

template <typename Iterator>
Iterator getPairMovePos(Iterator it, int moves) {
    std::advance(it, moves);
    return it;
}

template <typename Iterator>
bool isOrdered(Iterator first, Iterator second) {
    if(*first < *second) {
        return true;
    }
    return false;
}
