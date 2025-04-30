#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    int value;
    int i = 1;

    while (i < argc) {
        std::string arg(argv[i]);
        std::istringstream iss(arg);

        if (!(iss >> value)) {
            std::cerr << RED << "Error: " << RESET
                    << "Invalid input: " << YELLOW << arg << RESET << std::endl;
            return false;
        }
        if (value < 0) {
            std::cerr << RED << "Error: " << RESET
                    << "Negative numbers are not allowed: " << YELLOW << arg << RESET << std::endl;
            return false;
        }

        _vector.push_back(value);
        _deque.push_back(value);
        ++i;
    }
    return true;
}

void PmergeMe::displayBefore() const {
    std::cout << YELLOW << "Before:" << RESET;

    std::vector<int>::const_iterator it = _vector.begin();
    while (it != _vector.end()) {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << GREEN << "After:" << RESET;

    std::vector<int>::const_iterator it = _vector.begin();
    while (it != _vector.end()) {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::getVector() const {
    return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
    return _deque;
}

void PmergeMe::sortVector() {
    fordJohnsonSort(_vector);
}

void PmergeMe::sortDeque() {
    fordJohnsonSort(_deque);
}

template<typename Iterator>
void PmergeMe::insertionSort(Iterator begin, Iterator end) {
    typename Iterator::value_type key;
    Iterator j;
    Iterator i = begin + 1;
    
    while (i != end) {
        key = *i;
        j = i;
        while (j != begin && *(j - 1) > key) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
        ++i;
    }
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<size_t> sequence;
    size_t j0 = 0;
    size_t j1 = 1;
    size_t next;

    while (j1 <= n) {
        sequence.push_back(j1);
        next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    std::vector<bool> used(n + 1, false);
    std::vector<size_t> order;
    size_t i = 0;
    while (i < sequence.size()) {
        if (sequence[i] <= n && !used[sequence[i]]) {
            order.push_back(sequence[i]);
            used[sequence[i]] = true;
        }
        ++i;
    }
    i = 1;
    while (i <= n) {
        if (!used[i]) {
            order.push_back(i);
        }
        ++i;
    }
    return order;
}

template<typename Container>
void PmergeMe::mergePhase(Container& container, size_t groupSize) {
    if (groupSize >= container.size()) {
        return;
    }

    std::vector<Container> groups;
    typename Container::iterator it = container.begin();
    size_t i;

    while (it != container.end()) {
        Container group;
        i = 0;
        while (i < groupSize && it != container.end()) {
            group.push_back(*it);
            ++i;
            ++it;
        }
        insertionSort(group.begin(), group.end());
        groups.push_back(group);
    }

    i = 0;
    size_t j;
    while (i < groups.size()) {
        j = i + 1;
        while (j < groups.size()) {
            if (groups[i].back() > groups[j].back()) {
                Container tmp = groups[i];
                groups[i] = groups[j];
                groups[j] = tmp;
            }
            ++j;
        }
        ++i;
    }

    container.clear();
    i = 0;
    while (i < groups.size()) {
        container.insert(container.end(), groups[i].begin(), groups[i].end());
        ++i;
    }

    mergePhase(container, groupSize * 2);
}

template<typename Container>
void PmergeMe::splitMainPend(const Container& container, Container& main, Container& pend) {
    size_t mid = container.size() / 2;

    main.insert(main.end(), container.begin(), container.begin() + mid);
    pend.insert(pend.end(), container.begin() + mid, container.end());
}

template<typename Container>
void PmergeMe::insertionPhase(Container& main, Container& pend) {
    if (pend.empty()) {
        return;
    }

    std::vector<size_t> order = generateJacobsthal(pend.size());
    size_t i = 0;
    typename Container::iterator pos;
    while (i < order.size()) {
        if (order[i] == 0 || order[i] > pend.size()) {
            ++i;
            continue;
        }
        pos = std::lower_bound(main.begin(), main.end(), pend[order[i] - 1]);
        main.insert(pos, pend[order[i] - 1]);
        ++i;
    }
}

template<typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    if (container.size() <= 1) {
        return;
    }
    mergePhase(container, 1);
    
    Container main;
    Container pend;
    splitMainPend(container, main, pend);
    insertionPhase(main, pend);
    
    container = main;
}