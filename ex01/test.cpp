#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>    

void    calculate(std::stack<int> &_stack)
{
    int     a;
    int     b;
    char    op;
    int     result;

    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    op = _stack.top();
    if (op != '+' && op != '-' && op != '*' && op != '/')
    {
        std::cout << "Invalid expression" << std::endl;
        exit(1);
    }
    _stack.pop();
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            std::cout << "Error: division by zero" << std::endl;
            exit(1);
        }
        result = a / b;
    }
    _stack.push(result);
}

bool    isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

bool    checkForSpace(std::string exp)
{
    bool    isChar = false;
    if (exp.size() < 5)
        return (false);
    if (exp.find_first_not_of("0123456789+-*/ ") != std::string::npos)
        return (false);
    for (int i = 0; i < (int)exp.size(); i++)
    {
        if (isChar)
        {
            if (exp[i] != ' ')
                return (false);
            isChar = false;
        }
        if (isdigit(exp[i]) || isOperator(exp[i]))
            isChar = true;
    }
    return (true);
}

bool    checkIntegrity(std::string exp)
{
    bool   isDigit = true;
    bool   isOp = false;
    // std::string temp;
    exp.erase(std::remove(exp.begin(), exp.end(), ' '), exp.end());
    // std::cout << "test: " << exp << "--" << exp[exp.size() -1] << std::endl;
    if (!isOperator((exp[exp.size() -1])) || !isdigit(exp[0]) || !isdigit(exp[1]))
        return (false);
   
    for (int i = 2; i < (int)exp.size(); i++)
    {
        if (isDigit)
        {
            if (isdigit(exp[i]))
                return(false);
            isDigit = false;
            isOp = true;
        }
        else if (isOp)
        {
            if (isOperator(exp[i]))
                return (false);
            isDigit = true;
            isOp = false;
        }
    }
    return(true);
    /* Checking the alternance of spaces and operators*/
}

int        main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"" << std::endl;
        return (1);
    }
	std::stack<int>		_stack;
    std::string exp = av[1];
    if (!checkForSpace(exp) || !checkIntegrity(exp))
    {
        std::cout << "Error: Invalid expression" << std::endl;
        return (1);
    }

    std::reverse(exp.begin(), exp.end());
    std::stringstream ss(exp);
    char    token;
    // std::cout << exp.size() / 2 << std::endl;
    while(ss >> token)
    {
        if (isdigit(token))
            _stack.push(token - '0');
        else if (isOperator(token))
            _stack.push(token);
        else
        {
            std::cout << "Error: Invalid expression" << std::endl;
            return (1);
        }
    }
    while(_stack.size() > 1)
    {
        calculate(_stack);
    }
    std::cout << _stack.top() << std::endl;

 

    return (0);
}   