#include <iostream>
#include "iter.hpp"

void printInt(const int &n) {
    std::cout << n << " ";
}

void printString(const std::string &str) {
    std::cout << str << " ";
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"Hello", "World", "42", "C++"};

    std::cout << "Integer array: ";
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArr, 4, printString);
    std::cout << std::endl;

    return 0;
}
