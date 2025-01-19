#ifndef ITER_HPP
#define ITER_HPP

typedef unsigned int uint;

template <typename T>
void iter(T *arr, uint len, void (*f)(const T&))
{
    for (uint i = 0; i < len; i++)
        f(arr[i]);
}

#endif