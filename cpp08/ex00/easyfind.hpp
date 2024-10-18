#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <exception>
#include <list>
#include <algorithm> 
#include <vector>

#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define PINK "\033[38;5;200m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class MyException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("Element not found in this container");
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int nb)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), nb);
    if (it == container.end())
        throw MyException();
    return (it);
}

#endif