#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		PmergeMe(int ac, char **av);

		template <typename T>
		void display(const T& container)
		{
			typename T::const_iterator it;
			for (it = container.begin(); it != container.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		
		void mergeInsertSortDeque(std::deque<int>& arr);
		void mergeInsertSortList(std::list<int>& arr);
};

#endif