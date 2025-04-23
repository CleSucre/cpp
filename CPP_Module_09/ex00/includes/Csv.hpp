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

#include <iostream>
#include <map>
#include <istream>
#include <sstream>
#include <fstream>

#define DATA_FILE_NAME "data.csv"
#define SEPARATOR ','

class Csv {
    private:
        std::map<std::string, double> _data;
    public:
        Csv();
        Csv(std::ifstream& stream);
        Csv(const Csv& other);
        ~Csv();

        Csv& operator=(const Csv& other);

        void print() const;

        const std::map<std::string, double>& getData() const;
};

#endif //CSV_HPP
