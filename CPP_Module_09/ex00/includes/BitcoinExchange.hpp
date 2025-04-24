#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"

#define DATA_FILE_NAME "data.csv"
#define CSV_SEPARATOR ','
#define INPUT_SEPARATOR '|'

class BitcoinExchange {
    private:
        std::map<std::string, float> _data;
        int isDate(const std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(std::ifstream& stream);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);

        void print() const;
        float getValue(const std::string& date) const;
        void processInput(std::ifstream& stream);
};

#endif //BITCOINEXCHANGE_HPP
