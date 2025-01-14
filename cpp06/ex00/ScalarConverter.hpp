#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter() {}
    ~ScalarConverter() {}

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};

#endif