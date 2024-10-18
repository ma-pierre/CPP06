#include "span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try {
        std::cout << GREEN << "Creating a class span with nblist of size 5" << RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << GREEN << "Testing shortestSpan, answer should be 2 : " << RESET << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << GREEN << "Testing longestSpan, answer should be 14 : " << RESET << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << GREEN << " Creating a class span with nblist of size 3 : " << RESET << std::endl;
    try {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << GREEN << " Trying to add a 4th number, should throw an exeption: " << RESET << std::endl;
        sp.addNumber(4);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "Creating a class span with nblist of size 1 " << RESET << std::endl;
    try {
        Span sp = Span(1);
        sp.addNumber(5);
        std::cout << GREEN << "Looking for shortet span, should trow an exeption : " << RESET << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "Creating a class span with nblist of size 10000 " << RESET << std::endl;
    try {
        Span sp = Span(10000);
        for (int i = 0; i < 10000; ++i)
        {
            sp.addNumber(i);
        }
        std::cout << GREEN << " should print 1 :  " << RESET << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << GREEN << " should print 9999 :  " << RESET << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
