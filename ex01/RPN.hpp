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
		std::stack<int>		_stack;
		RPN();
		bool    isOperator(char c);
		bool    checkForSpace(std::string exp);
		bool    checkIntegrity(std::string exp);
	
	public:
		RPN(std::string	expression);
		RPN(const RPN & obj);
		~RPN();  
		
		void    calculate();
		void	printStack();
		RPN		&operator=(RPN const & obj); 
		

};
#endif
