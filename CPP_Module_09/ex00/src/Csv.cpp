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
    std::string date;
    float value;

    std::getline(stream, line);

    while (std::getline(stream, line)) {
        std::stringstream ss(line);

        std::getline(ss, date, CSV_SEPARATOR);

        if (!(ss >> value)) {
            continue;
        }

        if (!isDate(date)) {
            continue;
        }

        _data[date] = value;
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
    for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << ": " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

float Csv::getValue(const std::string& date) const {
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
