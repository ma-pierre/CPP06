#include "RPN.hpp"

bool ft_isoperator(char  c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/')
        return (true);
    return (false);
}

void calculateRPN(const std::string& userinput)
{
    std::stack<int> s;
    std::istringstream tokens(userinput);
    std::string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]))
            s.push(std::atoi(token.c_str()));
        else if (ft_isoperator(token[0]))
        {
            if (s.size() < 2)
            {
                std::cerr << "Error: Not enough operands for operation " << token << std::endl;
                exit(1);
            }
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            if (token == "+")
                s.push(op1 + op2);
            else if (token == "-")
                s.push(op1 - op2);
            else if (token == "*")
                s.push(op1 * op2);
            else if (token == "/")
                s.push(op1 / op2);
        }
        else 
        {
            std::cerr << "Error : Invalid RPN expression : '" << token << "'" << std::endl;
            exit(1);
        }
    }
    if (s.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression" << std::endl;
        exit(1);
    }
    std::cout << s.top() << std::endl;
}