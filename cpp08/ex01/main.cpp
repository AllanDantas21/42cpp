#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        std::cout << "Teste básico:" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
 
        std::cout << "\nTeste com 10000 números:" << std::endl;
        Span bigSpan(10000);
        std::vector<int> numbers;
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(std::rand());
        }
        
        bigSpan.addRange(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        std::cout << "\nTestando exceções:" << std::endl;
        Span small(1);
        small.addNumber(5);
        try {
            small.addNumber(3);
        } catch (const std::exception& e) {
            std::cout << "Exceção capturada: " << e.what() << std::endl;
        }

        Span empty(1);
        try {
            empty.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exceção capturada: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}