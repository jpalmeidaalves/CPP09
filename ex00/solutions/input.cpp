# include <iostream>
# include <map>
# include <fstream>

int main()
{
    std::map<std::string, float> db;
    std::fstream fs1;
    std::string str;
    std::string str2;
    std::pair<std::string, float> pair;

    fs1.open("../test.txt");
    getline(fs1, str );
    while (1)
    {
        getline(fs1, str, '|' );
        getline(fs1, str2, '\n' );
        pair = std::make_pair(str, std::atof(str2.c_str()));
        db.insert(pair);
        // std::cout << "key: " << str << "\nvalue: " << str2 << std::endl;
        if (fs1.eof()) 
            break;
    }
    fs1.close();
    for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;



    return (0);
}