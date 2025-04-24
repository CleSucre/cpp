/**
* ================================================================
 *  Project     : CPP_Module_09
 *  File        : Utils.hpp
 *
 *  Created by  : Julien Thomas on 23/04/2025
 * ================================================================
 */

#include "Utils.hpp"

/**
 * @brief Check if the string is a valid date format (YYYY-MM-DD)
 * 
 * @param std::string date
 * @return int 0 if the string is invalid format, 1 if is valid format
 *          2 if days are invalid, 3 if months are invalid
 */
int isDate(const std::string& date) {
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
    }

    if (day < 1 || day > 31) {
        return 2;
    }

    return 1;
}