#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>

// Helper function to generate date key in C++98.
static unsigned int generateKey(int y, int m, int d) {
    return y * 10000 + m * 100 + d;
}

void BitcoinExchange::isValidDate(int y, int m, int d) {
    if (y < 2000 || y > 2022 || m < 1 || m > 12 || d < 1 || d > 31)
        throw std::invalid_argument("Invalid date");
    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (m == 2 && isLeapYear && d > 29)
        throw std::invalid_argument("Invalid date");
    if (m == 2 && !isLeapYear && d > 28)
        throw std::invalid_argument("Invalid date");
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        throw std::invalid_argument("Invalid date");
}

BitcoinExchange::BitcoinExchange(const std::string dbName) {
    std::ifstream istrm(dbName.c_str());
    std::string line;
    
    if (!istrm.is_open())
        throw std::invalid_argument("could not open file");

    std::getline(istrm, line);
    while (std::getline(istrm, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        int y, m, d;
        float price;
        char hyphen, comma;
		
        ss >> y >> hyphen >> m >> hyphen >> d >> comma >> price;
        if (ss.fail() || !ss.eof() || price < 0 || comma != ',')
            throw std::invalid_argument("bad input");
		
        isValidDate(y, m, d);
        unsigned int key = generateKey(y, m, d);
        bitcoinPriceMap[key] = price;
    }
    if (bitcoinPriceMap.empty())
        throw std::invalid_argument("Empty file");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance) {
    *this = instance;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rvalue) {
    if (this != &rvalue)
        this->bitcoinPriceMap = rvalue.bitcoinPriceMap;
    return *this;
}

void BitcoinExchange::init(const std::string filename) {
    std::ifstream istrm(filename.c_str());
    std::string line;
    
    if (!istrm.is_open())
        throw std::invalid_argument("could not open file");

    std::getline(istrm, line);
    while (std::getline(istrm, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        int y, m, d;
        float count;
        char hyphen, bar;
        unsigned int key;

        try {
            ss >> y >> hyphen >> m >> hyphen >> d >> bar;
            if (ss.fail() || bar != '|')
                throw std::invalid_argument("bad input");
            isValidDate(y, m, d);
            key = generateKey(y, m, d);
            if (bitcoinPriceMap.begin()->first > key)
                throw std::invalid_argument("date is out of range");
            
            ss >> count;
            if (!ss.eof() || ss.fail())
                throw std::invalid_argument("bad input");
            if (count > 1000)
                throw std::invalid_argument("number is too big");
            if (count <= 0)
                throw std::invalid_argument("invalid number");
            
            std::map<unsigned int, float>::iterator it = bitcoinPriceMap.upper_bound(key);
            it--;
            std::cout << y << "-" 
                      << std::setfill('0') << std::setw(2) << m << "-" 
                      << std::setfill('0') << std::setw(2) << d 
                      << " => " << count << " = " << it->second * count << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}