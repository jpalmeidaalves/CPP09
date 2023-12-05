#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstring>
# include <string>
# include <cstdlib>
# include <iomanip>  

class BitcoinExchange 
{
	private:
		std::map<std::string, float> _db;
		std::map<std::string, float> _input;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		~BitcoinExchange();  
		
		int		getInput(char *inputFile);
		void	getValueByDate(std::string &buf);
		
		void	printDbMap(std::ostream & out);
		void	printInputMap();


		BitcoinExchange    &operator=(BitcoinExchange const & obj); 
		

};
std::ostream	&	operator<<(std::ostream & out, BitcoinExchange & obj);
#endif
