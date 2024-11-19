#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: This program requiered 1 argument. Try : ./btc input.csv" << std::endl;
        return (2);
    }
    calculateRPN(av[1]);
    return (0);
}