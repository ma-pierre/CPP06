#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    for (int i = 1; i < ac; i++)
    {
        if (!isdigit(atoi(av[i])))
        {
            std::cerr << "Errorwith argument " << av[i] << " :Only digits are accepted" << std::endl;
            return(1);
        }
    }
        
    return(0);  
}