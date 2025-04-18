#include "../include/PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>

bool parseArgs(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
    
    for (int i = 1; i < argc; i++) {
        
        char* endptr;
        long value = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || endptr == argv[i]) {
            std::cerr << "Error: '" << argv[i] << "' is not a valid integer." << std::endl;
            return false;
        }

        if (value > INT_MAX || value < 0) {
            std::cerr << "Error: '" << argv[i] << "' is out of positive integer range." << std::endl;
            return false;
        }
        vec.push_back(static_cast<int>(value));
    }
    deq.assign(vec.begin(), vec.end());
    return true;
}

template <typename Container>
void printContainer(Container& container) {
    for (typename Container::iterator it = container.begin();
         it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int maxComparisons(int n) {
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char** argv) {
    
    if (argc == 1) {
        std::cerr << "Error: ./PmergeMe [sequence]" << std::endl;
        std::exit(1);
    }

    std::vector<int> vec;
    vec.reserve(argc - 1);
    std::deque<int> deq;

    if (!parseArgs(argc, argv, vec, deq)) {
        return 1;
    }

    PmergeMe mergeContainer;

    std::cout << "Before: ";
    printContainer(vec);

    clock_t start_vec = clock();
    mergeContainer.mergeInsertSortVector(vec);
    clock_t end_vec = clock();
    double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;

    clock_t start_deq = clock();
    mergeContainer.mergeInsertSortDeque(deq);
    clock_t end_deq = clock();
    double deq_time = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After:  ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time << " us\n";
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deq_time << " us\n";

    return (0);
}