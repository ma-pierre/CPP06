#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << " Convert : error : wrong number of argumens \n ";
    else
        ScalarConverter::convert(av[1]);
    return (0);
}

