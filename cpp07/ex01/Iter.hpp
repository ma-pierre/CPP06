#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

const std::string ORANGE = "\033[38;5;214m";
const std::string RESET = "\033[0m"; 

template <typename T, typename Func>
void iter(T* array, int len, Func function)
{
    for (int i = 0; i < len; ++i)
        function(array[i]);
}

#endif
