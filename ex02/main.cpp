/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:11:32 by joaoalme          #+#    #+#             */
/*   Updated: 2023/12/08 20:11:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int    addToArr(int *arr, char *str, int index)
{
    std::stringstream   ss(str);
    int                 num;
    ss >> num;
    int i = 0;
    while(str[i] != '\0')
    {
        if (!isdigit(str[i]))
            return(1);
        i++;
    }
    if (ss.fail())
        return(2);
    arr[index] = num;
    return (0);
}

void    printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int     main(int ac, char **av)
{
    int arr[ac - 1];
    
    for(int i = 1; i < ac; i++)
    {
        if (addToArr(arr, av[i], i - 1) == 1)
        {
            std::cout << "Error: " << av[i] << " is not a valid input" << std::endl;
            return (1);
        }
        else if (addToArr(arr, av[i], i - 1) == 2)
        {
            std::cout << "Error: Integer overflow" << std::endl;
            return (1);
        }
    }
    PmergeMe    foo;
    std::cout << "Before: " << std::flush;
    printArr(arr, ac - 1);
    foo.SortDeque(arr, ac - 1);
    foo.SortList(arr, ac - 1);
    
    return (0);
}

