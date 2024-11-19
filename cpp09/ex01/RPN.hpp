#ifndef RPN_HPP
#define RPN_HPP


#include <stdint.h>
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

bool ft_isoperator(char  c);
void calculateRPN(const std::string& userinput);

#endif