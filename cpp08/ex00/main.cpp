#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

template <typename T>
void testEasyFind(T &container, int value) {
    try {
        typename T::iterator it = easyfind(container, value);
        std::cout << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    std::list<int> l(arr, arr + 5);

    testEasyFind(v, 3);
    testEasyFind(v, 6);
    testEasyFind(l, 2);
    testEasyFind(l, -1);

    return 0;
}
