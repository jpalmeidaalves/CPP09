#include <iostream>
#include "RPN.hpp"
RPN::RPN() {}

RPN::RPN(std::string exp)
{
	if (!checkExpression(exp))
    {
        std::cout << "Error: Invalid expression" << std::endl;
        exit(1);
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
void    RPN::calculate(std::string exp)
{
    std::stringstream ss(exp);
    while (ss >> token)
    {
        if (isdigit(token))
            this->_stack.push(token - '0');
        if ( isOperator(token))
        {
            if (this->_stack.size() < 2)
                exitError("Operand(s) is missing");
            op = token;
            b = this->_stack.top();
            this->_stack.pop();
            a = this->_stack.top();
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
                    exitError("Division by zero.");
                result = a / b;
            }
            std::cout << a <<  op << b << "=" << result << std::endl; // Uncoment to see operations
            this->_stack.push(result);
        }
	}
    if (this->_stack.size() != 1)
        exitError("Operator(s) is missing");
    std::cout << this->_stack.top() << std::endl;
}
bool	RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}
/* check if theres a space between each expression's characters*/
bool    RPN::checkExpression(std::string exp)
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

void    RPN::exitError(std::string str)
{
    std::cout << "Error: " << str << std::endl;
    exit(1);
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
