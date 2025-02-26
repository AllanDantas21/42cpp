#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& instance) : _arr(NULL), _size(0)
{
    *this = instance;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rvalue)
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

template <typename T>
T& Array<T>::operator[](std::size_t n)
{
    if (n >= _size)
        throw std::out_of_range("Index Out Of Range");
    return _arr[n];
}

template <typename T>
const T& Array<T>::operator[](std::size_t n) const
{
    if (n >= _size)
        throw std::out_of_range("Index Out Of Range");
    return _arr[n];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return _size;
}

#endif
