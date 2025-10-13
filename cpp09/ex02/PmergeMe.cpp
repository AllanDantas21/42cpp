#include "PmergeMe.hpp"

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

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container) {
    if (container.size() <= 1) {
        return;
    }
    
    int unpaired;
    std::vector<std::pair<int, int> > pairs = createPairsDeque(container, unpaired);
    
    sortPairsByComparison(pairs);
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    std::deque<int> result;

    separatePairsIntoChainsDeque(pairs, mainChain, pendChain);
    recursiveSortMainChainDeque(mainChain);
    buildSortedResultDeque(result, mainChain, pendChain, unpaired);
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

    separatePairsIntoChainsList(pairs, mainChain, pendChain);
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

double PmergeMe::measureSortTimeDeque(std::deque<int>& container) {
    clock_t start = clock();
    fordJohnsonSortDeque(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

double PmergeMe::measureSortTimeList(std::list<int>& container) {
    clock_t start = clock();
    fordJohnsonSortList(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

std::vector<std::pair<int, int> > PmergeMe::createPairsDeque(std::deque<int>& container, int& unpaired) {
    std::vector<std::pair<int, int> > pairs;
    unpaired = -1;
    
    std::deque<int> tempContainer = container;
    
    if (tempContainer.size() % 2 != 0) {
        unpaired = tempContainer.back();
        tempContainer.pop_back();
    }
    
    std::deque<int>::iterator it = tempContainer.begin();
    while (it != tempContainer.end()) {
        int first = *it++;
        if (it != tempContainer.end()) {
            int second = *it++;
            if (first < second) {
                pairs.push_back(std::make_pair(second, first));
            } else {
                pairs.push_back(std::make_pair(first, second));
            }
        }
    }
    
    return pairs;
}

std::vector<std::pair<int, int> > PmergeMe::createPairsList(std::list<int>& container, int& unpaired) {
    std::vector<std::pair<int, int> > pairs;
    unpaired = -1;
    
    std::list<int> tempContainer = container;
    
    if (tempContainer.size() % 2 != 0) {
        unpaired = tempContainer.back();
        tempContainer.pop_back();
    }
    
    std::list<int>::iterator it = tempContainer.begin();
    while (it != tempContainer.end()) {
        int first = *it++;
        if (it != tempContainer.end()) {
            int second = *it++;
            if (first < second) {
                pairs.push_back(std::make_pair(second, first));
            } else {
                pairs.push_back(std::make_pair(first, second));
            }
        }
    }
    
    return pairs;
}

void PmergeMe::insertElementsDeque(std::deque<int>& result, const std::vector<int>& elements) {
    for (std::vector<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), *it);
        result.insert(pos, *it);
    }
}

void PmergeMe::insertElementsList(std::list<int>& result, const std::vector<int>& elements) {
    for (std::vector<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), *it);
        result.insert(pos, *it);
    }
}

void PmergeMe::insertPendElementsDeque(std::deque<int>& result, 
    const std::vector<int>& pendChain, 
    const std::vector<int>&) {
    
    if (pendChain.empty()) return;
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
}

void PmergeMe::insertPendElementsList(std::list<int>& result, 
    const std::vector<int>& pendChain, 
    const std::vector<int>&) {
    
    if (pendChain.empty()) return;
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
}

void PmergeMe::insertUnpaired(std::deque<int>& result, int unpaired) {
    if (unpaired != -1) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
}

void PmergeMe::insertUnpaired(std::list<int>& result, int unpaired) {
    if (unpaired != -1) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
}

void PmergeMe::separatePairsIntoChainsDeque(const std::vector<std::pair<int, int> >& pairs,
                                            std::vector<int>& mainChain,
                                            std::vector<int>& pendChain) {
    mainChain.clear();
    pendChain.clear();
    
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); 
         it != pairs.end(); ++it) {
        mainChain.push_back(it->first);
        pendChain.push_back(it->second);
    }
}

void PmergeMe::separatePairsIntoChainsList(const std::vector<std::pair<int, int> >& pairs,
                                           std::vector<int>& mainChain,
                                           std::vector<int>& pendChain) {
    mainChain.clear();
    pendChain.clear();
    
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); 
         it != pairs.end(); ++it) {
        mainChain.push_back(it->first);
        pendChain.push_back(it->second);
    }
}

void PmergeMe::recursiveSortMainChainDeque(std::vector<int>& mainChain) {
    if (mainChain.empty()) {
        return;
    }
    
    std::deque<int> mainChainDeque(mainChain.begin(), mainChain.end());
    fordJohnsonSortDeque(mainChainDeque);
    mainChain.assign(mainChainDeque.begin(), mainChainDeque.end());
}

void PmergeMe::recursiveSortMainChainList(std::vector<int>& mainChain) {
    if (mainChain.empty()) {
        return;
    }
    
    std::list<int> mainChainList(mainChain.begin(), mainChain.end());
    fordJohnsonSortList(mainChainList);
    mainChain.assign(mainChainList.begin(), mainChainList.end());
}

void PmergeMe::buildSortedResultDeque(std::deque<int>& result,
                                      const std::vector<int>& mainChain,
                                      const std::vector<int>& pendChain,
                                      int unpaired) {
    result.clear();
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
        result.insert(pos, mainChain[i]);
    }
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
    
    if (unpaired != -1) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
}

void PmergeMe::buildSortedResultList(std::list<int>& result,
                                     const std::vector<int>& mainChain,
                                     const std::vector<int>& pendChain,
                                     int unpaired) {
    result.clear();
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
        result.insert(pos, mainChain[i]);
    }
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
    
    if (unpaired != -1) {
        std::list<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
}

void PmergeMe::displayDeque(const std::deque<int>& container) const {
    std::deque<int>::const_iterator it = container.begin();
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
    displayDeque(std::deque<int>(inputData.begin(), inputData.end()));
    
    std::deque<int> dequeData(inputData.begin(), inputData.end());
    double dequeTime = measureSortTimeDeque(dequeData);
    
    std::list<int> listData(inputData.begin(), inputData.end());
    double listTime = measureSortTimeList(listData);
    
    std::cout << "After: ";
    displayDeque(dequeData);
    
    std::cout << "Time to process a range of " << dequeData.size() 
              << " elements with std::deque container: " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << listData.size() 
              << " elements with std::list container: " << listTime << " us" << std::endl;
    
    std::vector<int> dequeVec(dequeData.begin(), dequeData.end());
    std::vector<int> listVec(listData.begin(), listData.end());
    
    if (dequeVec == listVec) {
        std::cout << "The sorted sequences are equal." << std::endl;
    } else {
        std::cout << "The sorted sequences are not equal." << std::endl;
    }
}

void PmergeMe::sortPairsByComparison(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].first > pairs[j].first) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    if (n <= 0) return sequence;
    
    sequence.push_back(1);
    if (n == 1) return sequence;
    
    sequence.push_back(3);
    if (n == 2) return sequence;
    
    for (int i = 2; i < n; ++i) {
        int next = sequence[i-1] + 2 * sequence[i-2];
        sequence.push_back(next);
    }
    
    return sequence;
}
