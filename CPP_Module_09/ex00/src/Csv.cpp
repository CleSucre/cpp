/**
* ================================================================
 *  Project     : CPP_Module_09
 *  File        : Csv.cpp
 *
 *  Created by  : Julien Thomas on 23/04/2025
 * ================================================================
 */

#include "Csv.hpp"

Csv::Csv() : _data() {}

Csv::Csv(std::ifstream& stream) {
    std::string line;

    std::getline(stream, line);

    while (std::getline(stream, line)) {
        std::stringstream ss(line);
        std::string date;
        double rate;

        std::getline(ss, date, ',');

        ss >> rate;

        _data[date] = rate;
    }
}

Csv::Csv(const Csv& csv) : _data(csv._data) {}

Csv::~Csv() {}

Csv& Csv::operator=(const Csv& csv) {
    _data = csv._data;
    return *this;
}

void Csv::print() const {
    std::cout << "CSV Data:" << std::endl;
    for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

const std::map<std::string, double>& Csv::getData() const {
    return _data;
}