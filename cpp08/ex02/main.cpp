#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack() {
    std::cout << "=== Testando MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    // Teste básico de push e pop
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Teste de iteradores
    std::cout << "Iterando forward:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Teste de iteradores reversos
    std::cout << "\nIterando reverse:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }
    
    // Teste de cópia
    std::stack<int> s(mstack);
    std::cout << "\nTamanho da pilha copiada: " << s.size() << std::endl;
}

void testList() {
    std::cout << "\n=== Testando std::list para comparação ===" << std::endl;
    
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "Size: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Iterando forward:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    testMutantStack();
    testList();
    
    return 0;
} 