#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <typeinfo>

class PmergeMe
{
private:
    std::vector<int> inputData;
    
    void fordJohnsonSortDeque(std::deque<int>& container);
    void fordJohnsonSortList(std::list<int>& container);
    
    std::vector<std::pair<int, int> > createPairsDeque(std::deque<int>& container, int& unpaired);
    std::vector<std::pair<int, int> > createPairsList(std::list<int>& container, int& unpaired);
    void insertElementsDeque(std::deque<int>& result, const std::vector<int>& elements);
    void insertElementsList(std::list<int>& result, const std::vector<int>& elements);
    void insertPendElementsDeque(std::deque<int>& result, const std::vector<int>& pendChain, const std::vector<int>&);
    void insertPendElementsList(std::list<int>& result, const std::vector<int>& pendChain, const std::vector<int>&);
    void insertUnpaired(std::deque<int>& result, int unpaired);
    void insertUnpaired(std::list<int>& result, int unpaired);
    void sortPairsByComparison(std::vector<std::pair<int, int> >& pairs);
    std::vector<int> generateJacobsthalSequence(int n);
    void separatePairsIntoChainsDeque(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain, std::vector<int>& pendChain);
    void separatePairsIntoChainsList(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain, std::vector<int>& pendChain);
    void recursiveSortMainChainDeque(std::vector<int>& mainChain);
    void recursiveSortMainChainList(std::vector<int>& mainChain);
    void buildSortedResultDeque(std::deque<int>& result, const std::vector<int>& mainChain, const std::vector<int>& pendChain, int unpaired);
    void buildSortedResultList(std::list<int>& result, const std::vector<int>& mainChain, const std::vector<int>& pendChain, int unpaired);
    void parseInput(int ac, char** av);
    bool isValidNumber(const std::string& str);
    double measureSortTimeDeque(std::deque<int>& container);
    double measureSortTimeList(std::list<int>& container);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    explicit PmergeMe(int ac, char **av);

    void displayDeque(const std::deque<int>& container) const;
    void displayList(const std::list<int>& container) const;
    
    void execute();
};

#endif