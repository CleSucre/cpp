/**
* ================================================================
 *  Project     : CPP_Module_09
 *  File        : Csv.hpp
 *
 *  Created by  : Julien Thomas on 23/04/2025
 * ================================================================
 */

#ifndef CSV_HPP
#define CSV_HPP

#include "Utils.hpp"
#include <iostream>
#include <map>
#include <istream>
#include <sstream>
#include <fstream>
#include <iomanip>

#define DATA_FILE_NAME "data.csv"
#define CSV_SEPARATOR ','

class Csv {
    private:
        std::map<std::string, float> _data;
    public:
        Csv();
        Csv(std::ifstream& stream);
        Csv(const Csv& other);
        ~Csv();

        Csv& operator=(const Csv& other);

        void print() const;
        float getValue(const std::string& date) const;
};

#endif //CSV_HPP
