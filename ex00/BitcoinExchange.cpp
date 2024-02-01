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
		std::cerr << "Fail opening source file";
		rdFile.close();
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
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj)
{
	*this = obj;
}
BitcoinExchange::~BitcoinExchange()
{
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
		out <<it->first << "  " << it->second << std::endl;
	}
}	

std::ostream &	operator<<(std::ostream & out, BitcoinExchange & obj)
{
	obj.printDbMap(out);
	return(out);
}

int		BitcoinExchange::getResult(char *inputFile)
{
	std::fstream	fs;
	std::string		line;
	std::string		date;
	char			sep;
    std::string		value;

	fs.open(inputFile, std::ios::in);
	if (fs.fail())
	{
		std::cerr << "Fail opening file";
		return (-1);
	}
	getline(fs, line);
	if (line != "date | value")
		std::cout << "Error: file does not match expected syntax" << std::endl;
	while (1)
    {
		getline(fs, line);
		std::stringstream ss(line);
        ss >> date >> sep >> value;
		if (sep != '|') 
        	std::cout << "Error: bad input => " << line << std::endl;
        else if (validateDate(date))
		{
            if (validateValue(atof(value.c_str())))
				std::cout <<  date << " => " << value << " = " << atof(value.c_str()) * searchInDb(date) << std::endl;
			else
				std::cout << "Error: Value must be beteewn 0 and 1000" << std::endl;
		}
        else 
            std::cout << "Error: bad input => " << line << std::endl;
        if (fs.eof()) 
            break;
    }
    fs.close();
	

	return 0;
}
bool	BitcoinExchange::validateDate(std::string& dateStr) const
{	
	std::stringstream s(dateStr);
	int	year, month, day;
	char dash1, dash2;
    int monthsDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (!(s >> year >> dash1 >> month >> dash2 >> day)
        || dash1 != '-' || dash2 != '-' || s.fail() || s.bad())
    {
        std::cout << "Invalid date format";
        return false;
    }
    if (year < 1970 || year > 2023 )
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > monthsDays[month])
        return false;
    return (true);
}

bool    BitcoinExchange::validateValue(float value) const
{
    if (value < 0 || value > 1000)
    {
        
        return (false);
    }
    return (true);
}

float	BitcoinExchange::searchInDb(std::string date)
{
	for (std::map<std::string, float>::reverse_iterator it = _db.rbegin(); it != _db.rend(); ++it)
	{
		if (it->first <= date)
			return (it->second);
	}
	return (0);
}	
