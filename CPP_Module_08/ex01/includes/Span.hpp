#ifndef SPAN_HPP
#define SPAN_HPP

#include <limits>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _data;

    public:
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int number);

        int shortestSpan() const;
        int longestSpan() const;
};

#endif // SPAN_HPP