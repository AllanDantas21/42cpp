#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;    
}

template <typename T>
const T& min(const T& first, const T& second)
{
	return (second > first ? first : second);
}

template <typename T>
const T& max(const T& first, const T& second)
{
	return (second < first ? first : second);
}

#endif