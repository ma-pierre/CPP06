/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:21:41 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/20 18:51:50 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>


const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m"; 
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";
const std::string ORANGE = "\033[38;5;214m";
const std::string PINK = "\033[38;5;200m";
const std::string BROWN = "\033[38;5;94m";
const std::string DARK_GREEN = "\033[38;5;22m";
const std::string FLASHY = "\033[38;5;202m";

class ScalarConverter
{
    public:
        ~ScalarConverter();
        
        static void convert(std::string input);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter& operator=(const ScalarConverter& other);
};  

void print_inf_f_nan(const std::string& literal);
bool check_inf_f_nan(const std::string& literal);
bool isPrintable(char c);
bool ft_isdigit(char c);

#endif