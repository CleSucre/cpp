#include "ScalarConverter.hpp"
#include "colors.h"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cerr << RED << "Usage: " << argv[0] << " <value>" << RESET << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
