#include "whatever.hpp"
#include <iostream>

void swapTest() {
    std::cout << "=== Teste de Swap ===" << std::endl;
    
    int a = 2;
    int b = 3;
    std::cout << "Antes: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "Depois: a = " << a << ", b = " << b << std::endl;
    
    std::string c = "primeira";
    std::string d = "segunda";
    std::cout << "Antes: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "Depois: c = " << c << ", d = " << d << std::endl;
}

void minMaxTest() {
    std::cout << "\n=== Teste de Min e Max ===" << std::endl;
    
    int x = 42;
    int y = 21;
    std::cout << "Valores: x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
    
    std::string str1 = "abc";
    std::string str2 = "xyz";
    std::cout << "\nStrings: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    std::cout << "min(str1, str2) = " << ::min(str1, str2) << std::endl;
    std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;
}

void differentTypesTest() {
    std::cout << "\n=== Teste com Diferentes Tipos ===" << std::endl;
    
    float f1 = 3.14f;
    float f2 = 2.71f;
    std::cout << "Floats: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    ::swap(f1, f2);
    std::cout << "Após swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    
    char ch1 = 'A';
    char ch2 = 'Z';
    std::cout << "\nChars: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
    std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;
}

void equalValuesTest() {
    std::cout << "\n=== Teste com Valores Iguais ===" << std::endl;
    
    int n1 = 10;
    int n2 = 10;
    std::cout << "Valores iguais: n1 = " << n1 << ", n2 = " << n2 << std::endl;
    std::cout << "min(n1, n2) = " << ::min(n1, n2) << std::endl;
    std::cout << "max(n1, n2) = " << ::max(n1, n2) << std::endl;
}

int main(void) {
    swapTest();
    minMaxTest();
    differentTypesTest();
    equalValuesTest();
    
    std::cout << "\n=== Todos os testes concluídos! ===" << std::endl;
    return 0;
}