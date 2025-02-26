#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {

    std::deque<int> inputDeque;
    std::list<int> inputList;

    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
    }
    std::cout << "Before: ";
    display(inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(inputDeque);
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (inputDeque == std::deque<int>(inputList.begin(), inputList.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    if (arr.size() % 2 != 0) {
        unpaired = arr.back();
        arr.pop_back();
    }
    
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            if (arr[i] < arr[i + 1])
                pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            else
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }
    
    std::deque<std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end());
    
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }
    
    std::deque<int> result;
    if (!mainChain.empty())
        result.push_back(mainChain[0]);
    
    for (size_t i = 1; i < mainChain.size(); ++i) {
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
    
    arr = result;
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    if (arr.size() <= 1)
        return;
    
    std::list<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    if (arr.size() % 2 != 0) {
        unpaired = arr.back();
        arr.pop_back();
    }
    
    std::list<int> copyArr = arr;
    
    std::list<int>::iterator it = copyArr.begin();
    while (it != copyArr.end()) {
        int first = *it++;
        if (it != copyArr.end()) {
            int second = *it++;
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        }
    }
    
    pairs.sort();
    
    std::list<int> mainChain;
    std::list<int> pendChain;
    
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        mainChain.push_back(it->first);
        pendChain.push_back(it->second);
    }
    
    std::list<int> result;
    
    for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
        std::list<int>::iterator pos = result.begin();
        for (; pos != result.end(); ++pos) {
            if (*pos > *it)
                break;
        }
        result.insert(pos, *it);
    }
    
    for (std::list<int>::iterator it = pendChain.begin(); it != pendChain.end(); ++it) {
        std::list<int>::iterator pos = result.begin();
        for (; pos != result.end(); ++pos) {
            if (*pos > *it)
                break;
        }
        result.insert(pos, *it);
    }
    
    if (unpaired != -1) {
        std::list<int>::iterator pos = result.begin();
        for (; pos != result.end(); ++pos) {
            if (*pos > unpaired)
                break;
        }
        result.insert(pos, unpaired);
    }
    
    arr = result;
}