#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
    private:
        std::map<unsigned int, float> bitcoinPriceMap;
        BitcoinExchange();
        static unsigned int makeKey(int y, int m, int d);
        static void validateDateOrThrow(int y, int m, int d);
        static std::string formatDate(int y, int m, int d);
        float findRateAtOrBefore(unsigned int key) const;
    public:
        explicit BitcoinExchange(const std::string& dbName);
        BitcoinExchange(const BitcoinExchange& instance);
        BitcoinExchange& operator=(const BitcoinExchange& rvalue);
        ~BitcoinExchange();

    void process(const std::string& filename);
};

#endif