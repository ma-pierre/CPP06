#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdint.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <limits>

#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define PINK "\033[38;5;200m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class Span
{
private:
    unsigned int    _N;
    std::list<int>  _lstNb;

public:
    Span();
    Span(const unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span& other);
    ~Span();
    void addNumber(int nb);
    int  shortestSpan() const;
    int  longestSpan() const;
    class NreachedException : public std::exception {
        virtual const char* what() const throw();
    };
    class NoSpanException : public std::exception {
        virtual const char* what() const throw();
    };

};

#endif
