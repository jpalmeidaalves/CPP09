#include "RPN.hpp"

int        main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"" << std::endl;
        return (1);
    }
    std::string exp = av[1];
    RPN     test(exp);
    RPN     copy = test;
    copy.printStack();
    std::cout << "test result: ";
    test.calculate(); 
    std::cout << "copy result: ";
    copy.calculate();   
    return (0);
}   