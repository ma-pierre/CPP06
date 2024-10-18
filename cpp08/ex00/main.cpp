#include "easyfind.hpp"

int main()
{
    std::cout << GREEN << "Creating an std::list<int> lst1 :" << RESET << std::endl;
    std::list<int>  lst1;

    std::cout << GREEN << "Assigning values to the int list [1] [17] [42] :" << RESET << std::endl;
    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);

    std::cout << GREEN << "trying easyfind(lst1, 42) , should find the value 42" << RESET << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst1, 42);
        std::cout << " Element found : " << *it << std::endl;
    } catch (const MyException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "trying easyfind(lst1, 24) , should throw an exeption" << RESET << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst1, 24);
        std::cout << " Element found found : " << *it << std::endl;
    } catch (const MyException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "Creating an std::vector<int> v1(10,42)" << RESET << std::endl;
    std::vector<int> v1(10, 42);

    std::cout << GREEN << "trying easyfind(v, 42) , should find the value 42" << RESET << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v1, 42);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const MyException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "trying easyfind(v, 2) , should throw an exeption" << RESET << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v1, 2);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const MyException& e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}