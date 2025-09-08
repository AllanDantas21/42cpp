#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>

static const int MIN_YEAR = 2000;
static const int MAX_YEAR = 2022;

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance) {
    *this = instance;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rvalue) {
    if (this != &rvalue)
        this->bitcoinPriceMap = rvalue.bitcoinPriceMap;
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& dbName) {
    std::ifstream istrm(dbName.c_str());
    std::string line;

    if (!istrm.is_open())
        throw std::invalid_argument("could not open file.");

    std::getline(istrm, line);
    while (std::getline(istrm, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        int y, m, d;
        float price;
        char h1, h2, comma;

        ss >> y >> h1 >> m >> h2 >> d >> comma >> price;
        if (ss.fail() || !ss.eof() || price < 0 || h1 != '-' || h2 != '-' || comma != ',')
            throw std::invalid_argument("bad input");

        validateDateOrThrow(y, m, d);
        unsigned int key = makeKey(y, m, d);
        bitcoinPriceMap[key] = price;
    }
    if (bitcoinPriceMap.empty())
        throw std::invalid_argument("Empty file");
}

void BitcoinExchange::process(const std::string& filename) {
    std::ifstream istrm(filename.c_str());
    std::string line;

    if (!istrm.is_open())
        throw std::invalid_argument("could not open file.");

    std::getline(istrm, line);
    while (std::getline(istrm, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        int y, m, d;
        float count;
        char h1, h2, bar;

        try {
            ss >> y >> h1 >> m >> h2 >> d >> bar;
            if (ss.fail() || h1 != '-' || h2 != '-' || bar != '|')
                throw std::invalid_argument(std::string("bad input => ") + line);

            validateDateOrThrow(y, m, d);
            unsigned int key = makeKey(y, m, d);

            ss >> count;
            if (!ss.eof() || ss.fail())
                throw std::invalid_argument(std::string("bad input => ") + line);
            if (count > 1000)
                throw std::invalid_argument("too large a number.");
            if (count <= 0)
                throw std::invalid_argument("not a positive number.");

            float rate = findRateAtOrBefore(key);
            std::cout << formatDate(y, m, d) << " => " << count << " = " << rate * count << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

static unsigned int clampMonthDayKeyPart(int m, int d) {
    return m * 100 + d;
}

unsigned int BitcoinExchange::makeKey(int y, int m, int d) {
    return y * 10000 + clampMonthDayKeyPart(m, d);
}

void BitcoinExchange::validateDateOrThrow(int y, int m, int d) {
    if (y < MIN_YEAR || y > MAX_YEAR || m < 1 || m > 12 || d < 1 || d > 31)
        throw std::invalid_argument("Invalid date");
    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (m == 2 && isLeapYear && d > 29)
        throw std::invalid_argument("Invalid date");
    if (m == 2 && !isLeapYear && d > 28)
        throw std::invalid_argument("Invalid date");
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        throw std::invalid_argument("Invalid date");
}

std::string BitcoinExchange::formatDate(int y, int m, int d) {
    std::ostringstream os;
    os << y << "-"
       << std::setfill('0') << std::setw(2) << m << "-"
       << std::setfill('0') << std::setw(2) << d;
    return os.str();
}

float BitcoinExchange::findRateAtOrBefore(unsigned int key) const {
    std::map<unsigned int, float>::const_iterator it = bitcoinPriceMap.upper_bound(key);
    if (it == bitcoinPriceMap.begin())
        throw std::invalid_argument("date is out of range");
    --it;
    return it->second;
}
