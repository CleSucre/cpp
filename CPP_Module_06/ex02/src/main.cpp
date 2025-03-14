#include "Identify.hpp"
#include "colors.h"

int main() {
    Base* obj = generate();

    std::cout << CYAN << "Identifying with pointer: ";
    identify(obj);
    std::cout << RESET;

    std::cout << MAGENTA << "Identifying with reference: ";
    identify(*obj);
    std::cout << RESET;

    delete obj;
    return 0;
}
