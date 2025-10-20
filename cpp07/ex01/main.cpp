#include <iostream>
#include "iter.hpp"

void printInt(const int &n) {
    std::cout << n << " ";
}

void printString(const std::string &str) {
    std::cout << str << " ";
}

void printDouble(const double &d) {
    std::cout << d << " ";
}

void printChar(const char &c) {
    std::cout << c << " ";
}

void incrementInt(int &n) {
    n++;
}

void doubleValue(int &n) {
    n *= 2;
}

void toUpperCase(char &c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

void basicTest() {
    std::cout << "=== Teste Básico ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"Hello", "World", "42rio", "C++"};

    std::cout << "Array de inteiros: ";
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Array de strings: ";
    iter(strArr, 4, printString);
    std::cout << std::endl;
}

void modificationTest() {
    std::cout << "\n=== Teste de Modificação ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    
    std::cout << "Array original: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;
    
    std::cout << "Incrementando cada elemento..." << std::endl;
    iter(numbers, 5, incrementInt);
    std::cout << "Array após incremento: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;
    
    std::cout << "Dobrando cada elemento..." << std::endl;
    iter(numbers, 5, doubleValue);
    std::cout << "Array após dobrar: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;
}

void differentTypesTest() {
    std::cout << "\n=== Teste com Diferentes Tipos ===" << std::endl;
    
    double doubleArr[] = {3.14, 2.71, 1.41, 1.73, 2.23};
    std::cout << "Array de doubles: ";
    iter(doubleArr, 5, printDouble);
    std::cout << std::endl;
    
    char charArr[] = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "Array de chars: ";
    iter(charArr, 5, printChar);
    std::cout << std::endl;
    
    std::cout << "Convertendo para maiúsculas..." << std::endl;
    iter(charArr, 5, toUpperCase);
    std::cout << "Array após conversão: ";
    iter(charArr, 5, printChar);
    std::cout << std::endl;
}

void largeArrayTest() {
    std::cout << "\n=== Teste com Array Grande ===" << std::endl;
    const int SIZE = 100;
    int largeArr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        largeArr[i] = i;
    }
    
    std::cout << "Processando array com " << SIZE << " elementos..." << std::endl;
    std::cout << "Primeiros 10 elementos: ";
    iter(largeArr, 10, printInt);
    std::cout << std::endl;
    
    iter(largeArr, SIZE, incrementInt);
    
    std::cout << "Após incremento, primeiros 10: ";
    iter(largeArr, 10, printInt);
    std::cout << std::endl;
    
    std::cout << "Últimos 10 elementos: ";
    iter(largeArr + (SIZE - 10), 10, printInt);
    std::cout << std::endl;
}

void edgeCasesTest() {
    std::cout << "\n=== Teste de Casos Especiais ===" << std::endl;
    
    int single[] = {42};
    std::cout << "Array com único elemento: ";
    iter(single, 1, printInt);
    std::cout << std::endl;
    
    int negatives[] = {-5, -3, -1, 0, 1, 3, 5};
    std::cout << "Array com negativos: ";
    iter(negatives, 7, printInt);
    std::cout << std::endl;
    
    iter(negatives, 7, incrementInt);
    std::cout << "Após incremento: ";
    iter(negatives, 7, printInt);
    std::cout << std::endl;
}

int main() {
    basicTest();
    modificationTest();
    differentTypesTest();
    largeArrayTest();
    edgeCasesTest();
    
    std::cout << "\n=== Todos os testes concluídos com sucesso! ===" << std::endl;
    return 0;
}
