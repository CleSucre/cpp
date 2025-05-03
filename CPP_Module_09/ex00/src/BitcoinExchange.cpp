#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data() {}

/**
 * @brief Constructor that reads data from a CSV file, parses it, and stores it in a map.
 * 
 * @param std::ifstream& stream
 */
BitcoinExchange::BitcoinExchange(std::ifstream& stream) {
    std::string line;
    std::string date;
    float value;

    while (std::getline(stream, line)) {
        std::stringstream ss(line);

        if (line.find("date") != std::string::npos) {
            continue;
        }

        std::getline(ss, date, CSV_SEPARATOR);

        if (!(ss >> value)) {
            continue;
        }

        if (!this->isDate(date)) {
            continue;
        }

        _data[date] = value;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btc) {
    _data = btc._data;
    return *this;
}

/**
 * @brief Get value from the map based on the date,
 *        using lower_bound to find the closest date if exact date is not found.
 * 
 * @param const std::string& date
 * @return float The value associated with the date or 0.0 if not found.
 */
float BitcoinExchange::getValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end()) {
        return 0.0f;
    }
    if (it->first != date) {
        if (it == _data.begin()) {
            return 0.0f;
        }
        --it;
    }
    return it->second;
}

/**
 * @brief Process input from a stream, parse each line, and print the result.
 *        It checks for errors in the date format and value.
 */
void BitcoinExchange::processInput(std::ifstream& stream) {
    std::string line;
    std::string date;
    float value;

    while (std::getline(stream, line)) {
        std::stringstream ss(line);

        if (line.find("date") != std::string::npos) {
            continue;
        }

        std::getline(ss, date, INPUT_SEPARATOR);

        date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));

        std::string::size_type pos = 0;
        while ((pos = date.find_first_of(" \t\n\r\f\v", pos)) != std::string::npos) {
            date.erase(pos, 1);
        }

        if (!(ss >> value)) {
            std::cerr << RED << "Error: " << RESET << "Invalid value for date: '" << date << "'" << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << RED << "Error: " << RESET << "Negative value for date: '" << date << "'" << std::endl;
            continue;
        }

        int date_check = this->isDate(date);
        if (date_check == 0) {
            std::cerr << RED << "Error: " << RESET << "Invalid date format: '" << date << "'" << std::endl;
            continue;
        } else if (date_check == 2) {
            std::cerr << RED << "Error: " << RESET << "Invalid day in date: '" << date << "'" << std::endl;
            continue;
        } else if (date_check == 3) {
            std::cerr << RED << "Error: " << RESET << "Invalid month in date: '" << date << "'" << std::endl;
            continue;
        }

        float price = this->getValue(date);
        std::cout << GREEN << "Date: " << RESET << date << " | "
                  << GREEN << "Value: " << RESET << value << " | "
                  << GREEN << "Price: " << RESET << price * value << std::endl;
    }
}

/**
 * @brief Check if the string is a valid date format (YYYY-MM-DD)
 * 
 * @param std::string date
 * @return int 0 if the string is invalid format, 1 if is valid format
 *          2 if days are invalid, 3 if months are invalid
 */
int BitcoinExchange::isDate(const std::string& date) {
    if (date.size() != 10) {
        return 0;
    }
    if (!(isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) &&
          date[4] == '-' &&
          isdigit(date[5]) && isdigit(date[6]) &&
          date[7] == '-' &&
          isdigit(date[8]) && isdigit(date[9]))) {
        return 0;
    }

    std::istringstream dayStream(date.substr(8, 9));
    std::istringstream monthStream(date.substr(5, 6));

    int day;
    int month;

    dayStream >> day;
    monthStream >> month;

    if (month < 1 || month > 12) {
        return 3;
    } else if (month == 2) {
        if (day < 1 || day > 29) {
            return 2;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            return 2;
        }
    } else {
        if (day < 1 || day > 31) {
            return 2;
        }
    }

    return 1;
}