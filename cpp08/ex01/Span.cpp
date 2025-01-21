#include "Span.hpp"

Span::Span(): N(0) {}

Span::Span(unsigned int n): N(n) {
}

Span::Span(const Span& instance) {
	N = instance.N;
	v = instance.v;
}

Span::~Span() {}

Span& Span::operator=(const Span& rvalue) {
	if (this != &rvalue) {
		this->N = rvalue.N;
		this->v = rvalue.v;
	}
	return *this;
}