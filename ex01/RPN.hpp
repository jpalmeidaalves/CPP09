#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>

class RPN 
{
	private:
		std::stack<int>	_stack;
		int     		a;
    	int     		b;
    	char    		op;
    	int     		result;
    	char    		token;

		RPN();
		bool    isOperator(char c);
		bool    checkExpression(std::string exp);
		void	exitError(std::string str);
	
	public:
		RPN(std::string	expression);
		RPN(const RPN & obj);
		~RPN();  
		
		void    calculate(std::string exp);
		void	printStack();
		RPN		&operator=(RPN const & obj); 
};

#endif

