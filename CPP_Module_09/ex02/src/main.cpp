#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

/**
 * @brief Get the Current Time object
 * 
 * @return double Current time in microseconds
 */
static double getCurrentTime() {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << RED << "Error: " << RESET
                  << "Please provide at least one number as an argument." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    if (!sorter.parseInput(argc, argv)) {
        return 2;
    }

    sorter.displayBefore();

    double startVec = getCurrentTime();
    sorter.sortVector();
    double endVec = getCurrentTime();

    double startDeq = getCurrentTime();
    sorter.sortDeque();
    double endDeq = getCurrentTime();

    sorter.displayAfter();

    std::cout << MAGENTA << "Time to process a range of "
              << YELLOW << sorter.getVector().size()
              << MAGENTA << " elements with std::vector : "
              << std::fixed << BLUE << std::setprecision(5)
              << (endVec - startVec) << " us" << RESET << std::endl;

    std::cout << MAGENTA << "Time to process a range of "
              << YELLOW << sorter.getDeque().size()
              << MAGENTA << " elements with std::deque : "
              << std::fixed << BLUE << std::setprecision(5)
              << (endDeq - startDeq) << " us" << RESET << std::endl;

    return 0;
}
