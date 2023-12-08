/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:11:36 by joaoalme          #+#    #+#             */
/*   Updated: 2023/12/08 20:13:48 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>


class PmergeMe 
{
	private:
		std::deque<int>	_deque;
		std::list<int>	_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		~PmergeMe();  
		
		void   	fillDeque(int *arr, int size);
		void	SortDeque(int *arr, int size);
		void 	divideDeque( std::deque<std::deque<int> >& dequeOfPairs, std::deque<int>& sortedDeque);
		void 	mergeDeque(std::deque<std::deque<int> >& dequeOfPairs, std::deque<int>& sortedDeque);
		void	insertDeque(std::deque<int>& sortedDeque, std::deque<std::deque<int> >& dequeOfPairs, int straggler);

		void   	fillList(int *arr, int size);
		void	SortList(int *arr, int size);
		void 	divideList( std::list<std::list<int> >& listOfPairs, std::list<int>& sortedList);
		void 	mergeList(std::list<std::list<int> >& listOfPairs, std::list<int>& sortedList);
		void	insertList(std::list<int>& sortedList, std::list<std::list<int> >& listOfPairs, int straggler);

		void    printDeque(void);
		void    printList(void);
		void 	printListOfLists(std::list<std::list<int> > listOfPairs);
		void 	printDequeOfDeque(std::deque<std::deque<int> > dequeOfPairs);

		PmergeMe    &operator=(const PmergeMe& obj); 
};

#endif
