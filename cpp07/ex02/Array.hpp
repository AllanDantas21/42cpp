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
    Array() : _arr(NULL), _size(0) {}

    Array(unsigned int n) : _arr(new T[n]), _size(n) {}

    Array(const Array& instance) : _arr(NULL), _size(0)
    {       
        *this = instance;
    }

    ~Array()
    {
        delete[] _arr;
    }

    Array& operator=(const Array& rvalue)
    {
        if (this == &rvalue)
            return *this;

        delete[] _arr;

        _size = rvalue._size;
        _arr = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
            _arr[i] = rvalue._arr[i];

        return *this;
    }

    T& operator[](std::size_t n)
    {
        if (n >= _size)
            throw std::out_of_range("Index Out Of Range");
        return _arr[n];
    }

    const T& operator[](std::size_t n) const
    {
        if (n >= _size)
            throw std::out_of_range("Index Out Of Range");
        return _arr[n];
    }

    std::size_t size() const
    {
        return _size;
    }
};

#endif
