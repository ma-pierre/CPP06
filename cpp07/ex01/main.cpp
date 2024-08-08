#include "Iter.hpp"

template <typename T>
void ft_print(T const &nod)
{
    std::cout << '[' << nod << "] ";
}

int main(void)
{
    int tab[] = {1, 2, 3, 4, 5, 6 , 7, 8 , 9, 10};
    char ctab[] = {'b','o','n','j','o','u','r'};

    std::cout << ORANGE << " TEST TAB OF 10 INT : should diplay the tab from 1 to 10" << RESET << "\n";
    iter(tab, 10, ft_print<int>);
    std::cout << std::endl;
    std::cout << ORANGE << " TEST TAB OF 7 char  : should diplay : B o n j o u r "<< RESET << "\n";
    iter(ctab, 7, ft_print<char>);
    std::cout << std::endl;

}