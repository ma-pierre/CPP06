#include <iostream>
#include "Array.hpp"

int main()
{
    
        std::cout << GREEN << "Creating array A of size 5 :" << RESET << std::endl;
        Array<int> A(5);

        std::cout << GREEN << "giving value to this A Array :" << RESET << std::endl;
        for (unsigned int i = 0; i < A.size(); ++i)
        {
            A[i] = i * 10;
            std::cout << "A[" << i << "] = " << A[i] << std::endl;
        }

        std::cout << GREEN << "Creating and testing copy with copy constructor :" << RESET << std::endl;
        Array<int> B = A;
    
        B[0] = 100;
        std::cout << "A[0] = " << A[0] << ", B[0] = " << B[0] << std::endl;

        std::cout << GREEN << "testing limits, an exeption should appear :" << RESET << std::endl;
        try
        {
            std::cout << A[10] << std::endl;
        } 
        catch (const std::out_of_range& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    return (0);

}