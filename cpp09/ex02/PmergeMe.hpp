#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <utility>

class PmergeMe
{
private:
    std::vector<int> inputData;
    
    void fordJohnsonSortVector(std::vector<int>& container);
    void fordJohnsonSortList(std::list<int>& container);
    
    std::vector<std::pair<int, int> > createPairsVector(std::vector<int>& container, int& unpaired);
    std::vector<std::pair<int, int> > createPairsList(std::list<int>& container, int& unpaired);
    void insertElementsVector(std::vector<int>& result, const std::vector<int>& elements);
    void insertElementsList(std::list<int>& result, const std::vector<int>& elements);
    void insertPendElementsVector(std::vector<int>& result, const std::vector<int>& pendChain);
    void insertPendElementsList(std::list<int>& result, const std::vector<int>& pendChain);
    void insertUnpaired(std::vector<int>& result, int unpaired);
    void insertUnpaired(std::list<int>& result, int unpaired);
    void sortPairsByComparison(std::vector<std::pair<int, int> >& pairs);
    std::vector<int> generateJacobsthalSequence(int n);
    void separatePairsIntoChains(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain, std::vector<int>& pendChain);
    void recursiveSortMainChainVector(std::vector<int>& mainChain);
    void recursiveSortMainChainList(std::vector<int>& mainChain);
    void buildSortedResultVector(std::vector<int>& result, const std::vector<int>& mainChain, const std::vector<int>& pendChain, int unpaired);
    void buildSortedResultList(std::list<int>& result, const std::vector<int>& mainChain, const std::vector<int>& pendChain, int unpaired);
    void parseInput(int ac, char** av);
    bool isValidNumber(const std::string& str);
    double measureSortTimeVector(std::vector<int>& container);
    double measureSortTimeList(std::list<int>& container);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe(int ac, char **av);

    void displayVector(const std::vector<int>& container) const;
    void displayList(const std::list<int>& container) const;
    
    void execute();
};

#endif