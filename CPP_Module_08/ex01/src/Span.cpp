#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_data.size() >= _maxSize) {
        throw std::overflow_error("Span is already full");
    }
    _data.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_data.size() + std::distance(begin, end) > _maxSize) {
        throw std::overflow_error("Span is already full");
    }
    _data.insert(_data.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_data.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_data.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}