# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

bool	validateDate(std::string& dateStr)
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

bool    validateValue(float value)
{
    if (value < 0 || value > 1000)
    {
        std::cout << "Error: Value must be beteewn 0 and 1000" << std::endl;
        return (false);
    }
    return (true);
}
int main()
{
    std::ifstream   fs1;
    std::string     date;
    std::string     value;

    fs1.open("../test.txt");
    getline(fs1, date );
    while (1)
    {
        getline(fs1, date, '|' );
        getline(fs1, value, '\n' );
        if (validateDate(date))
            std::cout << date;
        else 
            std::cout << "Error: bad input =>" << date << std::endl;
        if(validateValue(atof(value.c_str())))
            std::cout << "\nvalue: " << value << std::endl;
        if (fs1.eof()) 
            break;
    }
    fs1.close();
    return (0);
}