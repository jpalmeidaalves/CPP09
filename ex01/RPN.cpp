#include <iostream>
#include "RPN.hpp"
RPN::RPN() {}

RPN::RPN(std::string exp)
{
	if (!checkForSpace(exp) || !checkIntegrity(exp))
    {
        std::cout << "Error: Invalid expression" << std::endl;
        exit(1);
    }
   
    std::reverse(exp.begin(), exp.end());
    std::stringstream ss(exp);
    char    token;
    while(ss >> token)
    {
        if (isdigit(token))
            _stack.push(token - '0');
        else if (isOperator(token))
            _stack.push(token);
        else
        {
            std::cout << "Error: Invalid expression" << std::endl;
            exit(1);
        }
    }
}

RPN::RPN(const RPN & obj)
{
	*this = obj;
	return;
}
RPN::~RPN()
{
	return;
}
RPN    &RPN::operator=( RPN const & obj)
{
	this->_stack = obj._stack;
	return(*this);
}
/*	Calculates the expression by executing one operation at time 
	Pops the two first numbers and the operator from the stack
	Then pushes the result back to the stack */
void    RPN::calculate()
{
	int     a;
    int     b;
    char    op;
    int     result;
	while(_stack.size() > 1)
    {
		a = this->_stack.top();
		this->_stack.pop();
		b = this->_stack.top();
		this->_stack.pop();
		op = this->_stack.top();
		if (op != '+' && op != '-' && op != '*' && op != '/')
		{
			std::cout << "Invalid expression" << std::endl;
			exit(1);
		}
		this->_stack.pop();
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
		this->_stack.push(result);
	}
    std::cout << this->_stack.top() << std::endl;
}
bool	RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}
/* check if theres a space between each expression's characters*/
bool    RPN::checkForSpace(std::string exp)
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

/* Check the alternance between spaces and operators*/
bool    RPN::checkIntegrity(std::string exp)
{
    bool   isDigit = true;
    bool   isOp = false;
    exp.erase(std::remove(exp.begin(), exp.end(), ' '), exp.end());
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
}

void	RPN::printStack()
{
	std::stack<int> tmp = this->_stack;
	while (!tmp.empty())
	{
		if (tmp.top() >= 0 && tmp.top() <= 9)
			std::cout << tmp.top();
		else 
			std::cout << static_cast<char>(tmp.top());
		std::cout << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}
