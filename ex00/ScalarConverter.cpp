/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:21:45 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/20 19:14:57 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << BLUE << "ScalarConverter Constructor called " << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << BLUE << "ScalarConverter Destructor called " << RESET << std::endl;
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    if (this != &cpy)
        *this = cpy;
    std::cout << "Copy constructor called for : ScalarConverter " << std::endl;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

bool check_inf_f_nan(const std::string& literal)
{
    return (literal == "-inf" || literal == "+inf" || literal == "nan" ||
            literal == "-inff" || literal == "+inff" || literal == "nanf");
}

void print_inf_f_nan(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        std::cout << RED << "char: impossible\nint: impossible\nfloat: " << literal 
                    << "\ndouble: " << literal.substr(0, literal.size() - 1) << RESET << std::endl;
    else
        std::cout << RED << "char: impossible\nint: impossible\nfloat: " << literal
                    << "f\ndouble: " << literal << RESET << std::endl;
}

bool    ft_isprintable(char c)
{
    return (c >= 32 && c <= 122);
}

void    ScalarConverter::convert(std::string input)
{
    if (check_inf_f_nan(input) == true)
    {
        print_inf_f_nan(input);
        return;
    }
    if (!input[1] && ft_isprintable(input[0]) && !isdigit(input[0]))
    {
        char c = input[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << PINK << "char: " << c << "\n" << RESET;
        std::cout << YELLOW << "int: " << i << "\n" << RESET;
        std::cout << ORANGE << "float: " << f << "f\n" << RESET;
        std::cout << FLASHY << "double: " << d << "\n" << RESET;
        return;
    }
    std::istringstream iss(input);
    double  d;
    if (!(iss >> d))
    {
        std::cout << RED << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n" << RESET;   
        return;
    }
    int     i = static_cast<int>(d);
    float   f = static_cast<float>(d);
    char    c = static_cast<char>(i);
     
    if (ft_isprintable(c))
        std::cout << PINK << "char: " << c << "\n" << RESET;
    else
        std::cout << PINK << "char: Non displayable\n" << RESET;
    std::cout << YELLOW << "int: " << i << "\n" << RESET;
    std::cout << ORANGE << "float: " << f << "f\n" << RESET;
    std::cout << FLASHY << "double: " << d << "\n" << RESET;
}
