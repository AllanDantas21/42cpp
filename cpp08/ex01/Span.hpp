#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>
# include <iterator>
# include <vector>
# include <list>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	v;

		Span();
    public:
        Span(unsigned int n);
		Span(const Span& instance);
		Span& operator=(const Span& rvalue);
		~Span();
}

#endif