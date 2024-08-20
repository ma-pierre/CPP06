#include "Whatever.hpp"

int main( void ) 
{
std::cout << GREEN << "Creating int A and int B " << RESET << std::endl;
int a = 2;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << GREEN << "Swaping A and B with swap fonction" << RESET << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << GREEN << "testing fonction min " << RESET << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << GREEN << "testing fonction max " << RESET << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::cout << GREEN << "Creating string C and string D " << RESET << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "C = " << c << ", D = " << d << std::endl;
std::cout << GREEN << "Swaping C and D with swap fonction  " << RESET << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << GREEN << "testing fonction min " << RESET << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << GREEN << "testing fonction max " << RESET << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return (0);
}