#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
        return (std::cerr << "Error: No input sequence provided.\n", 1);

    try {
        PmergeMe pmergeMe(ac, av);
        pmergeMe.execute();
    } catch (const std::exception& e) {
        return (std::cerr << e.what() << "\n", 1);
    }
    
    return (0);
}