#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

class Fixed {
    private:
        int                 _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();

        Fixed &operator=(const Fixed &src);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif //FIXED_HPP
