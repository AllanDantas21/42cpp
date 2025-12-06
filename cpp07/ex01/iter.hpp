#ifndef ITER_HPP
#define ITER_HPP

typedef unsigned int uint;

template <typename T, typename F>
void iter(T *arr, const uint len, F f)
{
    for (uint i = 0; i < len; i++)
        f(arr[i]);
}

#endif