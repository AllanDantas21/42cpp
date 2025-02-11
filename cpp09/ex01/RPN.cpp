#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include <stdexcept>

RPN::RPN(std::string &input): _input(input) {}

RPN::~RPN() {}

RPN::RPN(const RPN& instance) {
    *this = instance;
}

RPN& RPN::operator=(const RPN& rvalue) {
    if (this != &rvalue)
        this->_input = rvalue._input;
    return *this;
}

int RPN::init() {
    std::stack<int, std::list<int> > s;
    std::stringstream ss(_input);

    char c;
    while (ss >> c) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (c == '+' || c == '-' || c == '/' || c == '*') {
            if (s.size() < 2)
                throw std::invalid_argument("Not valid expression");

            int rhs = s.top(); s.pop();
            int lhs = s.top(); s.pop();
            int res = 0;

            switch (c) {
                case '+': res = lhs + rhs; break;
                case '-': res = lhs - rhs; break;
                case '*': res = lhs * rhs; break;
                case '/':
                    if (rhs == 0)
                        throw std::invalid_argument("Divide by zero");
                    res = lhs / rhs;
                    break;
                default:
                    throw std::invalid_argument("Not valid operator");
            }
            s.push(res);
        } else {
            throw std::invalid_argument("Not valid operator");
        }
    }

    if (s.size() != 1)
        throw std::invalid_argument("Not valid expression");

    return s.top();
}