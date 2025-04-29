#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        template<typename Iterator>
        void insertionSort(Iterator begin, Iterator end);

        std::vector<size_t> generateJacobsthal(size_t n);

        template<typename Container>
        void mergePhase(Container& container, size_t groupSize);

        template<typename Container>
        void splitMainPend(const Container& container, Container& main, Container& pend);

        template<typename Container>
        void insertionPhase(Container& main, Container& pend);

        template<typename Container>
        void fordJohnsonSort(Container& container);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& other);

        bool parseInput(int argc, char** argv);

        void sortVector();
        void sortDeque();

        void displayBefore() const;
        void displayAfter() const;

        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;
};

#endif