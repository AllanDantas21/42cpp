#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    char* end;
    double value = std::strtod(literal.c_str(), &end);

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    }

    if (*end != '\0' && *end != 'f') {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    ScalarConverter::printChar(value);
    ScalarConverter::printInt(value);
    ScalarConverter::printFloat(value);
    ScalarConverter::printDouble(value);
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    float f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (floor(f) == f) std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: " << value;
    if (floor(value) == value) std::cout << ".0";
    std::cout << std::endl;
}