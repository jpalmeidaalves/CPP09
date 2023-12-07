#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
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
		
		int		getResult(char *inputFile);
		bool	validateDate(std::string& date) const;
		bool    validateValue(float value) const;
		float	searchInDb(std::string date);
		
		void	printDbMap(std::ostream & out);


		BitcoinExchange    &operator=(BitcoinExchange const & obj); 
		

};
std::ostream	&	operator<<(std::ostream & out, BitcoinExchange & obj);
#endif
