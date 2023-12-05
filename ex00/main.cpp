#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./btc [ipnut_file]";
        return (1);
    }
    BitcoinExchange test;
    test.getInput(av[1]);
    // test.printInputMap();
    // std::cout << test;
    return (0);
}