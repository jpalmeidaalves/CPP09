# include <iostream>
# include <map>
# include <fstream>

int main()
{
    std::map<std::string, float> db;
    std::ifstream	rdFile;
	std::string		line;
	std::string		svalue;
	float			fvalue;
	size_t			comma;

	rdFile.open("data.csv", std::ios::in);
	while (rdFile >> line)
	{
		comma = line.find(',');
		svalue = line.substr(comma + 1);
		fvalue = std::atof(svalue.c_str());
		db.insert(std::pair<std::string, float>(line.substr(0, comma), fvalue));
	}
	rdFile.close();
    for(std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
	
    return 0;
}
