#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include "colors.h"

template<typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    Array(const Array& other) : _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = (_size > 0) ? new T[_size] : NULL;
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    unsigned int size() const {
        return _size;
    }

    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range(RED "Index out of bounds!" RESET);
        return _data[index];
    }
};

#endif //ARRAY_HPP
