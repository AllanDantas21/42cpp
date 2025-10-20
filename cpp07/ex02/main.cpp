#include "Array.hpp"
#include <string>

void basicTest() {
    std::cout << "=== Teste Básico ===" << std::endl;
    
    Array<int> numbers(5);
    std::cout << "Array criado com tamanho: " << numbers.size() << std::endl;
    
    std::cout << "Preenchendo array: ";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 10;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void copyTest() {
    std::cout << "\n=== Teste de Cópia ===" << std::endl;
    
    Array<int> original(4);
    for (std::size_t i = 0; i < original.size(); ++i) {
        original[i] = i + 1;
    }
    
    std::cout << "Array original: ";
    for (std::size_t i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int> copy(original);
    copy[0] = 999;
    
    std::cout << "Cópia modificada: ";
    for (std::size_t i = 0; i < copy.size(); ++i) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Original inalterado: ";
    for (std::size_t i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
}

void differentTypesTest() {
    std::cout << "\n=== Teste com Diferentes Tipos ===" << std::endl;
    
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42rio";
    strings[2] = "C++";
    
    std::cout << "Array de strings: ";
    for (std::size_t i = 0; i < strings.size(); ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;
}

void exceptionTest() {
    std::cout << "\n=== Teste de Exceções ===" << std::endl;
    
    Array<int> arr(5);
    
    std::cout << "Acessando índice válido [2]: ";
    try {
        arr[2] = 42;
        std::cout << arr[2] << " OK" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
    
    std::cout << "Tentando acessar índice inválido [10]: ";
    try {
        std::cout << arr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }
}

int main() {
    try {
        basicTest();
        copyTest();
        differentTypesTest();
        exceptionTest();
        
        std::cout << "\n=== Todos os testes concluídos! ===" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\nErro: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
