#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void) {
    std::srand(std::clock());
    switch (std::rand() % 3) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << 'A' << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << 'B' << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << 'C' << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << 'B' << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << 'C' << std::endl;
        return;
    } catch (std::exception&) {}
}

int main() {
    Base* base = generate();
    A a;
    B b;
    C c;

    identify(base);
    identify(a);
    identify(b);
    identify(c);

    delete base;
    return 0;
}
