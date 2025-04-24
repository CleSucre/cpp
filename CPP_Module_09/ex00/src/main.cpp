/**
* ================================================================
 *  Project     : CPP_Module_09
 *  File        : main.cpp
 *
 *  Created by  : Julien Thomas on 23/04/2025
 * ================================================================
 */

#include "colors.h"
#include "Csv.hpp"
#include <fstream>
#include <sstream>

void processInput(std::ifstream& stream, Csv& csv) {
    std::string line;
    std::string date;
    float value;

    std::getline(stream, line);

    while (std::getline(stream, line)) {
        std::stringstream ss(line);

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

        int date_check = isDate(date);
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

        float price = csv.getValue(date);
        std::cout << GREEN << "Date: " << RESET << date << " | "
                  << GREEN << "Value: " << RESET << value << " | "
                  << GREEN << "Price: " << RESET << price * value << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    if (argc <= 1) {
        std::cout << RED << "Usage: " << argv[0] << " [input.txt]" << RESET << std::endl;
        return 1;
    }

    std::ifstream data_file(DATA_FILE_NAME);
    if (!data_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << DATA_FILE_NAME << "'" << std::endl;
        return 1;
    }
    Csv csv(data_file);
    data_file.close();

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << argv[1] << "'" << std::endl;
        return 1;
    }
    processInput(input_file, csv);

    input_file.close();

    return 0;
}
