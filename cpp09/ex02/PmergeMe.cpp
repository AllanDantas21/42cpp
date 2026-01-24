#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

template<typename Iterator>
void handleUnpair(Iterator, Iterator end, size_t& size, int& unpaired) {
    unpaired = -1;
    if (size % 2 != 0) {
        Iterator last = end;
        --last;
        unpaired = *last;
        size--;
    }
}

template<typename Iterator>
std::pair<int, int> handlePair(int first, int second) {
    if (first > second)
        return std::make_pair(first, second);
    return std::make_pair(second, first);
}

template<typename Iterator>
std::vector<std::pair<int, int> > createPairsFromIterators(Iterator begin, Iterator end, size_t size, int& unpaired) {
    std::vector<std::pair<int, int> > pairs;
    handleUnpair(begin, end, size, unpaired);

    Iterator it = begin;
    for (size_t i = 0; i < size; i += 2) {
        int first = *it++;
        int second = *it++;
        pairs.push_back(handlePair<Iterator>(first, second));
    }
    return pairs;
}

template<typename Container>
void insertElementBinarySearch(Container& result, int value) {
    typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), value);
    result.insert(pos, value);
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : inputData(other.inputData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        inputData = other.inputData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
    parseInput(ac, av);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& container) {
    if (container.size() <= 1) return;
    
    int unpaired;
    std::vector<std::pair<int, int> > pairs = createPairsVector(container, unpaired);
    std::vector<int> mainChain;

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    recursiveSortMainChainVector(mainChain);
    std::vector<int> pendChain;

    for (size_t i = 0; i < mainChain.size(); ++i) {
        int winner = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winner) {
                pendChain.push_back(pairs[j].second);
                break;
            }
        }
    }

    std::vector<int> result;
    buildSortedResultVector(result, mainChain, pendChain, unpaired);
    
    container = result;
}

void PmergeMe::recursiveSortMainChainVector(std::vector<int>& mainChain) {
    fordJohnsonSortVector(mainChain);
}

void PmergeMe::buildSortedResultVector(std::vector<int>& result,
                                       const std::vector<int>& mainChain,
                                       const std::vector<int>& pendChain,
                                       int unpaired) {
    result = mainChain;
    
    if (!pendChain.empty()) {
        result.insert(result.begin(), pendChain[0]);
        std::vector<int> remainingPend(pendChain.begin() + 1, pendChain.end());
        insertPendElementsVector(result, remainingPend);
    }
    
    insertUnpaired(result, unpaired);
}

void PmergeMe::insertPendElementsVector(std::vector<int>& result, const std::vector<int>& pendChain) {
    if (pendChain.empty()) return;
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendChain.size());
    
    for (size_t k = 0; k < jacobsthal.size(); ++k) {
        int idx = jacobsthal[k];
        
        if (idx < (int)pendChain.size()) {
            int valueToInsert = pendChain[idx];
            insertElementBinarySearch(result, valueToInsert);
        }
    }
}

void PmergeMe::fordJohnsonSortList(std::list<int>& container) {
    if (container.size() <= 1) return;

    int unpaired;
    std::vector<std::pair<int, int> > pairs = createPairsList(container, unpaired);
    std::list<int> mainChain;

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    recursiveSortMainChainList(mainChain);
    std::vector<int> pendChain;
    
    for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
        int winner = *it;
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winner) {
                pendChain.push_back(pairs[j].second);
                break;
            }
        }
    }

    std::list<int> result;
    buildSortedResultList(result, mainChain, pendChain, unpaired);
    container = result;
}

void PmergeMe::recursiveSortMainChainList(std::list<int>& mainChain) {
    fordJohnsonSortList(mainChain);
}

void PmergeMe::buildSortedResultList(std::list<int>& result,
                                     const std::list<int>& mainChain,
                                     const std::vector<int>& pendChain,
                                     int unpaired) {
    result = mainChain;

    if (!pendChain.empty()) {
        result.insert(result.begin(), pendChain[0]);

        std::vector<int> remainingPend(pendChain.begin() + 1, pendChain.end());
        insertPendElementsList(result, remainingPend);
    }

    insertUnpaired(result, unpaired);
}

void PmergeMe::insertPendElementsList(std::list<int>& result, const std::vector<int>& pendChain) {
    if (pendChain.empty()) return;
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendChain.size());
    
    for (size_t k = 0; k < jacobsthal.size(); ++k) {
        int idx = jacobsthal[k];
        if (idx < (int)pendChain.size()) {
            int valueToInsert = pendChain[idx];
            insertElementBinarySearch(result, valueToInsert);
        }
    }
}

void PmergeMe::parseInput(int ac, char** av) {
    for (int i = 1; i < ac; ++i) {
        std::string input(av[i]);
        if (!isValidNumber(input)) {
            throw std::invalid_argument("Error");
        }
        std::istringstream iss(input);
        int value;
        iss >> value;
        if (value < 0) throw std::invalid_argument("Error");
        inputData.push_back(value);
    }
    if (inputData.empty()) throw std::invalid_argument("Error");
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    size_t start = 0;
    if (str[0] == '+') start = 1;
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

double PmergeMe::measureSortTimeVector(std::vector<int>& container) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    fordJohnsonSortVector(container);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_nsec - start.tv_nsec) / 1000.0;
    return elapsed;
}

double PmergeMe::measureSortTimeList(std::list<int>& container) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    fordJohnsonSortList(container);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_nsec - start.tv_nsec) / 1000.0;
    return elapsed;
}

std::vector<std::pair<int, int> > PmergeMe::createPairsVector(std::vector<int>& container, int& unpaired) {
    return createPairsFromIterators(container.begin(), container.end(), container.size(), unpaired);
}

std::vector<std::pair<int, int> > PmergeMe::createPairsList(std::list<int>& container, int& unpaired) {
    return createPairsFromIterators(container.begin(), container.end(), container.size(), unpaired);
}

void PmergeMe::insertElementsVector(std::vector<int>& result, const std::vector<int>& elements) {
    for (size_t i = 0; i < elements.size(); ++i) insertElementBinarySearch(result, elements[i]);
}
void PmergeMe::insertElementsList(std::list<int>& result, const std::vector<int>& elements) {
    for (size_t i = 0; i < elements.size(); ++i) insertElementBinarySearch(result, elements[i]);
}

void PmergeMe::insertUnpaired(std::vector<int>& result, int unpaired) {
    if (unpaired != -1) insertElementBinarySearch(result, unpaired);
}
void PmergeMe::insertUnpaired(std::list<int>& result, int unpaired) {
    if (unpaired != -1) insertElementBinarySearch(result, unpaired);
}


void PmergeMe::displayVector(const std::vector<int>& container) const {
    for (size_t i = 0; i < container.size(); ++i) std::cout << container[i] << (i < container.size() - 1 ? " " : "");
    std::cout << std::endl;
}
void PmergeMe::displayList(const std::list<int>& container) const {
    for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ) {
        std::list<int>::const_iterator current = it;
        ++it;
        std::cout << *current;
        if (it != container.end()) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    displayVector(std::vector<int>(inputData.begin(), inputData.end()));

    std::vector<int> vectorData(inputData.begin(), inputData.end());
    double vectorTime = measureSortTimeVector(vectorData);

    std::list<int> listData(inputData.begin(), inputData.end());
    double listTime = measureSortTimeList(listData);

    std::cout << "After:  ";
    displayVector(vectorData);

    std::cout << "Time to process a range of " << vectorData.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << listData.size() 
              << " elements with std::list   : " << std::fixed << std::setprecision(5) 
              << listTime << " us" << std::endl;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    if (n <= 0) return sequence;
    
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    
    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    
    int last_jac = 1; 

    for (size_t k = 0; k < jacobsthal.size(); ++k) {
        int curr_jac = jacobsthal[k];
        int limit = curr_jac;
        if (limit > n) limit = n;
        
        for (int i = limit - 1; i >= last_jac - 1; --i) {
             if (i < n) sequence.push_back(i);
        }
        last_jac = curr_jac + 1;
    }
    
    int i = last_jac - 1;
    while (i < n) {
        sequence.push_back(i);
        i++;
    }
    
    return sequence;
}