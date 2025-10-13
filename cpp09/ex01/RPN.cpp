#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <vector>
#include <stdexcept>
#include <cctype>

static const char* kErrInvalidExpression = "Not valid expression";
static const char* kErrInvalidOperator = "Not valid operator";
static const char* kErrDivideByZero = "Divide by zero";
static bool isOperator(char c);
static int applyOperator(char op, int lhs, int rhs);

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

int RPN::process() {
    std::stack<int> values;
    std::stringstream inputStream(_input);

    char token;
    while (inputStream >> token) {
        if (std::isdigit(static_cast<unsigned char>(token))) {
            values.push(token - '0');
            continue;
        }

        if (isOperator(token)) {
            if (values.size() < 2)
                throw std::invalid_argument(kErrInvalidExpression);

            int rhs = values.top(); values.pop();
            int lhs = values.top(); values.pop();
            const int result = applyOperator(token, lhs, rhs);
            values.push(result);
            continue;
        }

        throw std::invalid_argument(kErrInvalidOperator);
    }

    if (values.size() != 1)
        throw std::invalid_argument(kErrInvalidExpression);

    return values.top();
}

static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*';
}

static int applyOperator(char op, int lhs, int rhs) {
    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0) throw std::invalid_argument(kErrDivideByZero);
            return lhs / rhs;
        default:
            throw std::invalid_argument(kErrInvalidOperator);
    }
}