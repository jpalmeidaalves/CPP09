#include <iostream>
#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
	std::ifstream	rdFile;
	std::string		line;
	std::string		svalue;
	float			fvalue;
	size_t			comma;

	rdFile.open("data.csv", std::ios::in);
	if (rdFile.fail())
	{
		std::cerr << "Fail opening file";
		exit(1);
	}
	while (rdFile >> line)
	{
		comma = line.find(',');
		svalue = line.substr(comma + 1);
		fvalue = std::atof(svalue.c_str());
		this->_db.insert(std::pair<std::string, float>(line.substr(0, comma), fvalue));
	}
	rdFile.close();
	return;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj)
{
	*this = obj;
	return;
}
BitcoinExchange::~BitcoinExchange()
{
	return;
}
BitcoinExchange    &BitcoinExchange::operator=( BitcoinExchange const & obj)
{
	if (this != &obj)
	{
		this->_db = obj._db;
	}
	return(*this);
}

void	BitcoinExchange::printDbMap(std::ostream & out)
{
	for(std::map<std::string, float>::iterator it = this->_db.begin(); it != this->_db.end(); ++it)
	{
		out <<it->first << "," << it->second << std::endl;
	}
}	
void	BitcoinExchange::printInputMap()
{
	for(std::map<std::string, float>::iterator it = this->_input.begin(); it != this->_input.end(); ++it)
	{
		std::cout <<it->first << "," << it->second << std::endl;
	}
}	

std::ostream &	operator<<(std::ostream & out, BitcoinExchange & obj)
{
	obj.printDbMap(out);
	return(out);
}

int		BitcoinExchange::getInput(char *inputFile)
{
	std::fstream		filestream;
	std::string			buf;

	filestream.open(inputFile, std::ios::in);
	if (filestream.fail())
	{
		std::cerr << "Fail opening file";
		return (-1);
	}
	getline(filestream, buf);
	if (buf != "date | value")
		std::cout << "Error: file does not match expected syntax" << std::endl;
	while (getline(filestream, buf))
	{
		this->getValueByDate(buf);
	}

}
void	getValueByDate(const std::string& buf)
{
	std::stringstream	strStreamBuf(buf);
	std::string			date;
	std::string			amount;

	getline(strStreamBuf, date, '|');
	std::cout << date << std::endl;
}

// int		BitcoinExchange::getInput(char *inputFile)
// {
// 	std::fstream	istream;
// 	std::string		line, s1, pipe, s2;
// 	// float			amount;


// 	istream.open(inputFile, std::ios::in);
// 	if (istream.fail())
// 	{
// 		std::cerr << "Fail opening file";
// 		return (-1);
// 	}
// 	std::getline(istream, s1);
// 	std::cout << s1 << std::endl;
// 	while (!istream.eof())
// 	{
// 		std::getline(istream, line);
// 		istream >> s1 >> pipe >> s2;
// 		// amount = atof(s2.c_str());
// 		std::cout << s1 << std::endl;
// 		std::cout << pipe << std::endl;
// 		std::cout << s2 << std::endl;
// 	}
// 	return(0);
// }
