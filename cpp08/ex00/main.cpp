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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

    testEasyFind(v, 3);
    testEasyFind(l, 213);

    return 0;
}
