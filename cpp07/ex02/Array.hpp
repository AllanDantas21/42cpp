#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
    T* _arr;
    std::size_t _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& instance);
    ~Array();
    
    Array& operator=(const Array& rvalue);
    T& operator[](std::size_t n);
    const T& operator[](std::size_t n) const;
    std::size_t size() const;
};

#include "Array.tpp"

#endif
