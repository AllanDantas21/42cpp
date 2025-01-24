#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
	unsigned int N;
	std::vector<int> numbers;

public:
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	Span& operator=(const Span& other);

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		unsigned int distance = std::distance(begin, end);
		if (numbers.size() + distance > N)
			throw std::runtime_error("Não há espaço suficiente para adicionar todos os números");
		numbers.insert(numbers.end(), begin, end);
	}
};

#endif