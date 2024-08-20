#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define PINK "\033[38;5;200m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T const &a, T const &b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(T const &a, T const &b)
{
    return (a > b) ? a : b;
}

#endif
