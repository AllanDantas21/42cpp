#include "PmergeMe.hpp"

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
    return std::make_pair(std::max(first, second), std::min(first, second));
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
void insertPendElement(Container& result, int pendValue) {
    typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), pendValue);
    result.insert(pos, pendValue);
}

template<typename Container>
void insertUnpairedElement(Container& result, int unpaired) {
    if (unpaired != -1) {
        typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
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
    if (container.size() <= 1) {
        return;
    }
    
    int unpaired;
    std::vector<std::pair<int, int> > pairs = createPairsVector(container, unpaired);
    
    sortPairsByComparison(pairs);
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    std::vector<int> result;

    separatePairsIntoChains(pairs, mainChain, pendChain);
    recursiveSortMainChainVector(mainChain);
    buildSortedResultVector(result, mainChain, pendChain, unpaired);
    container = result;
}

void PmergeMe::fordJohnsonSortList(std::list<int>& container) {
    if (container.size() <= 1) {
        return;
    }
    
    int unpaired;
    std::vector<std::pair<int, int> > pairs = createPairsList(container, unpaired);
    
    sortPairsByComparison(pairs);
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    std::list<int> result;

    separatePairsIntoChains(pairs, mainChain, pendChain);
    recursiveSortMainChainList(mainChain);
    buildSortedResultList(result, mainChain, pendChain, unpaired);
    container = result;
}

void PmergeMe::parseInput(int ac, char** av) {
    for (int i = 1; i < ac; ++i) {
        std::string input(av[i]);
        if (!isValidNumber(input)) {
            throw std::invalid_argument("Error: Invalid input value \"" + input + 
                                      "\". Only positive integers are allowed.");
        }
        
        std::istringstream iss(input);
        int value;
        iss >> value;
        
        if (value <= 0) {
            throw std::invalid_argument("Error: Invalid input value \"" + input + 
                                      "\". Only positive integers are allowed.");
        }
        
        inputData.push_back(value);
    }
    
    if (inputData.empty()) {
        throw std::invalid_argument("Error: No valid input provided.");
    }
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    
    std::istringstream iss(str);
    int value;
    iss >> value;
    return iss.eof() && !iss.fail();
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
    for (std::vector<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), *it);
        result.insert(pos, *it);
    }
}

void PmergeMe::insertElementsList(std::list<int>& result, const std::vector<int>& elements) {
    for (std::vector<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), *it);
        result.insert(pos, *it);
    }
}

void PmergeMe::insertPendElementsVector(std::vector<int>& result, 
    const std::vector<int>& pendChain) {
    
    if (pendChain.empty()) return;
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendChain.size() + 1);
    std::vector<bool> inserted(pendChain.size(), false);
    
    int prev_jac = 1;
    for (size_t j = 0; j < jacobsthal.size(); ++j) {
        int jac = jacobsthal[j];
        int start_idx = jac - 2;
        int end_idx = prev_jac - 1;
        
        for (int i = start_idx; i >= end_idx && i >= 0; --i) {
            if (static_cast<size_t>(i) < pendChain.size() && !inserted[i]) {
                insertPendElement(result, pendChain[i]);
                inserted[i] = true;
            }
        }
        prev_jac = jac;
    }
    
    for (int i = static_cast<int>(pendChain.size()) - 1; i >= 0; --i) {
        if (!inserted[i]) {
            insertPendElement(result, pendChain[i]);
        }
    }
}

void PmergeMe::insertPendElementsList(std::list<int>& result, 
    const std::vector<int>& pendChain) {
    
    if (pendChain.empty()) return;
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendChain.size() + 1);
    std::vector<bool> inserted(pendChain.size(), false);
    
    int prev_jac = 1;
    for (size_t j = 0; j < jacobsthal.size(); ++j) {
        int jac = jacobsthal[j];
        int start_idx = jac - 2;
        int end_idx = prev_jac - 1;
        
        for (int i = start_idx; i >= end_idx && i >= 0; --i) {
            if (static_cast<size_t>(i) < pendChain.size() && !inserted[i]) {
                insertPendElement(result, pendChain[i]);
                inserted[i] = true;
            }
        }
        prev_jac = jac;
    }
    
    for (int i = static_cast<int>(pendChain.size()) - 1; i >= 0; --i) {
        if (!inserted[i]) {
            insertPendElement(result, pendChain[i]);
        }
    }
}

void PmergeMe::insertUnpaired(std::vector<int>& result, int unpaired) {
    insertUnpairedElement(result, unpaired);
}

void PmergeMe::insertUnpaired(std::list<int>& result, int unpaired) {
    insertUnpairedElement(result, unpaired);
}

void PmergeMe::separatePairsIntoChains(const std::vector<std::pair<int, int> >& pairs,
                                       std::vector<int>& mainChain,
                                       std::vector<int>& pendChain) {
    mainChain.clear();
    pendChain.clear();
    
    if (pairs.empty()) return;
    
    mainChain.push_back(pairs[0].first);
    mainChain.push_back(pairs[0].second);
    
    for (size_t i = 1; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    } 
}

void PmergeMe::recursiveSortMainChainVector(std::vector<int>& mainChain) {
    if (mainChain.size() <= 1) {
        return;
    }
    
    if (mainChain.size() == 2) {
        if (mainChain[0] > mainChain[1]) {
            std::swap(mainChain[0], mainChain[1]);
        }
        return;
    }
    
    std::vector<int> mainChainVector(mainChain.begin(), mainChain.end());
    fordJohnsonSortVector(mainChainVector);
    mainChain.assign(mainChainVector.begin(), mainChainVector.end());
}

void PmergeMe::recursiveSortMainChainList(std::vector<int>& mainChain) {
    if (mainChain.size() <= 1) {
        return;
    }
    
    if (mainChain.size() == 2) {
        if (mainChain[0] > mainChain[1]) {
            std::swap(mainChain[0], mainChain[1]);
        }
        return;
    }
    
    std::list<int> mainChainList(mainChain.begin(), mainChain.end());
    fordJohnsonSortList(mainChainList);
    mainChain.assign(mainChainList.begin(), mainChainList.end());
}

void PmergeMe::buildSortedResultVector(std::vector<int>& result,
                                      const std::vector<int>& mainChain,
                                      const std::vector<int>& pendChain,
                                      int unpaired) {
    result.assign(mainChain.begin(), mainChain.end());
    insertPendElementsVector(result, pendChain);
    insertUnpaired(result, unpaired);
}

void PmergeMe::buildSortedResultList(std::list<int>& result,
                                     const std::vector<int>& mainChain,
                                     const std::vector<int>& pendChain,
                                     int unpaired) {
    result.assign(mainChain.begin(), mainChain.end());
    insertPendElementsList(result, pendChain);
    insertUnpaired(result, unpaired);
}

void PmergeMe::displayVector(const std::vector<int>& container) const {
    std::vector<int>::const_iterator it = container.begin();
    if (it != container.end()) {
        std::cout << *it;
        ++it;
    }
    for (; it != container.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::displayList(const std::list<int>& container) const {
    std::list<int>::const_iterator it = container.begin();
    if (it != container.end()) {
        std::cout << *it;
        ++it;
    }
    for (; it != container.end(); ++it) {
        std::cout << " " << *it;
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
    
    std::cout << "After: ";
    displayVector(vectorData);
    
    std::cout << "Time to process a range of " << vectorData.size() 
              << " elements with std::vector container: " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << listData.size() 
              << " elements with std::list container: " << std::fixed << std::setprecision(5) 
              << listTime << " us" << std::endl;
}

void PmergeMe::sortPairsByComparison(std::vector<std::pair<int, int> >& pairs) {
    std::sort(pairs.begin(), pairs.end());
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    if (n <= 0) return sequence;
    
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    
    while (true) {
        int a = jacobsthal[jacobsthal.size() - 2];
        int b = jacobsthal[jacobsthal.size() - 1];
        int next = b + 2 * a;
        
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    
    for (size_t k = 0; k < jacobsthal.size(); ++k) {
        int jk = jacobsthal[k];
        
        if (jk - 1 < n) {
            sequence.push_back(jk - 1);
        }
        
        int jk_prev = (k == 0) ? 0 : jacobsthal[k - 1];
        
        for (int j = jk - 2; j >= jk_prev; --j) {
            if (j < n && j >= 0) {
                sequence. push_back(j);
            }
        }
    }
    
    return sequence;
}