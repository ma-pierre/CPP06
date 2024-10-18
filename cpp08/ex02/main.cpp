#include "MutantStack.hpp"
#include <iostream>
#include <list>

// Définir des macros pour les couleurs si le terminal les supporte
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main() 
{
    
        std::cout << GREEN << "Testing MutantStack :" << RESET << std::endl;

        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << "Top of stack: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << GREEN << "Iterating through MutantStack:" << RESET << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);

    ////// TRYING THE SAME WITH LIST//////
        std::cout << GREEN << "Testing with std::list:" << RESET << std::endl;

        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);

        std::cout << "Top of list: " << lstack.back() << std::endl;

        lstack.pop_back();

        std::cout << "Size after pop: " << lstack.size() << std::endl;

        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);

        std::list<int>::iterator it_lst = lstack.begin();
        std::list<int>::iterator ite_lst = lstack.end();

        ++it_lst;
        --it_lst;

        std::cout << GREEN << "Iterating through std::list:" << RESET << std::endl;
        while (it_lst != ite_lst)
        {
            std::cout << *it_lst << std::endl;
            ++it_lst;
        }

    return(0);
}
