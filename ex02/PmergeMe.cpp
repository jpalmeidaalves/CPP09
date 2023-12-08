/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:11:28 by joaoalme          #+#    #+#             */
/*   Updated: 2023/12/08 20:13:19 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
	return;
}

PmergeMe::~PmergeMe()
{
	return;
}

PmergeMe    &PmergeMe::operator=( const PmergeMe& obj)
{
	if (this != &obj)
	{
		this->_deque = obj._deque;
		this->_list = obj._list;
	}
	return (*this);
}

/* ------- List methods ------- */

void	PmergeMe::fillList(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->_list.push_back(arr[i]);
	}
}



void	PmergeMe::printList(void)
{
	std::list<int>::iterator itbegin = _list.begin();
	std::list<int>::iterator itend = _list.end();
	std::cout << "List: ";
	while (itbegin != itend)
	{
		std::cout << *itbegin << " ";
		itbegin++;
	}
	std::cout << std::endl;
}


/* 	Group the elements of X into n/2 pairs of elements, arbitrarily, 
	leaving one element unpaired if there is an odd number of elements */
/*	Recursively sort the n/2 larger elements from each pair, creating a
	sorted sequence S of n/2 of the input elements, in ascending order. */
void	PmergeMe::SortList(int *arr, int size)
{
	struct timeval t1, t2;
	std::list<std::list<int> > listOfPairs;
	std::list<int> sortedList;
	
	gettimeofday(&t1, NULL);
	this->fillList(arr, size);
	int straggler = -1;
	if (size % 2 != 0)
	{
		straggler = this->_list.back();
		this->_list.pop_back();
	}
	this->divideList(listOfPairs, sortedList);
	this->insertList(sortedList, listOfPairs, straggler);
	std::cout << "After(list) : ";
	for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	gettimeofday(&t2, NULL);
	std::cout << "Time to process a range of "<< size << " elements with std::list: " 
			<< (t2.tv_usec - t1.tv_usec) << " us" << std::endl;
}


/* Perform n/2 comparisons, one per pair, to determine the larger of the two elements in each pair. */
void	PmergeMe::divideList(std::list<std::list<int> >& listOfPairs, std::list<int>& sortedList)
{
	for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
	{
		std::list<int> temp;
		temp.push_back(*it);
		it++;
		if (*it > temp.front())
			temp.push_back(*it);
		else
			temp.push_front(*it);
		listOfPairs.push_back(temp);
	}
	this->mergeList(listOfPairs,sortedList);
	// printListOfLists(listOfPairs);
}

void	PmergeMe::mergeList(std::list<std::list<int> >& listOfPairs, std::list<int>& sortedList)
{
	for(std::list<std::list<int> >::iterator it = listOfPairs.begin(); it != listOfPairs.end(); it++)
	{
		if (sortedList.size() == 0)
			sortedList.push_back(it->front());
		else
		{
			for (std::list<int>::iterator it2 = sortedList.begin(); it2 != sortedList.end(); it2++)
			{
				if (it->front() > sortedList.back())
					sortedList.push_back(it->front());
				else if (it->front() < *it2)
				{
					sortedList.insert(it2, it->front());
					break;
				}
			}
		}
	}
}

void	PmergeMe::insertList(std::list<int>& sortedList, std::list<std::list<int> >& listOfPairs, int straggler)
{
	
	for(std::list<std::list<int> >::iterator it = listOfPairs.begin(); it != listOfPairs.end(); it++)
	{
		for (std::list<int>::iterator it2 = sortedList.begin(); it2 != sortedList.end(); it2++)
		{
			if (it->back() > sortedList.back())
			{
				sortedList.push_back(it->back());
				break;
			}
			if (it->back() < *it2)
			{
				sortedList.insert(it2, it->back());
				break;
			}
		}
	}
	if (straggler != -1)
	{
		for (std::list<int>::iterator it2 = sortedList.begin(); it2 != sortedList.end(); it2++)
		{
			if (straggler > sortedList.back())
			{
				sortedList.push_back(straggler);
				break;
			}
			if (straggler < *it2)
			{
				sortedList.insert(it2, straggler);
				break;
			}
		}
	}
	this->_list.push_back(straggler);
}

void 	PmergeMe::printListOfLists(std::list<std::list<int> > listOfPairs)
{
	for (std::list<std::list<int> >::iterator it = listOfPairs.begin(); it != listOfPairs.end(); it++)
	{
		for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/* ------- Deque methods ------- */

void	PmergeMe::fillDeque(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->_deque.push_back(arr[i]);
	}
}

void	PmergeMe::SortDeque(int *arr, int size)
{
	
	struct timeval t1, t2;
	std::deque<std::deque<int> > dequeOfPairs;
	std::deque<int> sortedDeque;
	// int temp;
	
	gettimeofday(&t1, NULL);
	this->fillDeque(arr, size);
	int straggler = -1;
	if (size % 2 != 0)
	{
		straggler = this->_deque.back();
		this->_deque.pop_back();
	}
	this->divideDeque(dequeOfPairs, sortedDeque);
	// printdequeOfdeques(dequeOfPairs);	
	this->insertDeque(sortedDeque, dequeOfPairs, straggler);
	std::cout << "After(Deque): ";
	for (std::deque<int>::iterator it = sortedDeque.begin(); it != sortedDeque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	gettimeofday(&t2, NULL);
	std::cout << "Time to process a range of "<< size << " elements with std::deque: " 
			<< (t2.tv_usec - t1.tv_usec) << " us" << std::endl;
}	
void	PmergeMe::divideDeque(std::deque<std::deque<int> >& dequeOfPairs, std::deque<int>& sortedDeque)
{
	
	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); it++)
	{
		std::deque<int> temp;
		temp.push_back(*it);
		it++;
		if (*it > temp.front())
			temp.push_back(*it);
		else
			temp.push_front(*it);
		dequeOfPairs.push_back(temp);
	}
	this->mergeDeque(dequeOfPairs,sortedDeque);
	// printDequeOfDeques(dequeOfPairs);
}	

void	PmergeMe::mergeDeque(std::deque<std::deque<int> >& dequeOfPairs, std::deque<int>& sortedDeque)
{
	for(std::deque<std::deque<int> >::iterator it = dequeOfPairs.begin(); it != dequeOfPairs.end(); it++)
	{
		if (sortedDeque.size() == 0)
			sortedDeque.push_back(it->front());
		else
		{
			for (std::deque<int>::iterator it2 = sortedDeque.begin(); it2 != sortedDeque.end(); it2++)
			{
				if (it->front() > sortedDeque.back())
				{
					sortedDeque.push_back(it->front());
					break;
				}
				if (it->front() < *it2)
				{
					sortedDeque.insert(it2, it->front());
					break;
				}
			}
		}
	}
}

void	PmergeMe::insertDeque(std::deque<int>& sortedDeque, std::deque<std::deque<int> >& dequeOfPairs, int straggler)
{
	
	for(std::deque<std::deque<int> >::iterator it = dequeOfPairs.begin(); it != dequeOfPairs.end(); it++)
	{
		for (unsigned int i = 0; i < sortedDeque.size(); i++)
		{
			if (it->back() > sortedDeque.back())
			{
				sortedDeque.push_back(it->back());
				break;
			}
			if (it->back() < sortedDeque[i])
			{
				sortedDeque.insert(sortedDeque.begin() + i, it->back());
				break;
			}
		}
	}
	if (straggler != -1)
	{
		int i = 0;
		while (straggler > sortedDeque[i])
		{
			i++;
		}
		sortedDeque.insert(sortedDeque.begin() + i, straggler);
	}
	this->_deque.push_back(straggler);
}

void 	PmergeMe::printDequeOfDeque(std::deque<std::deque<int> > dequeOfPairs)
{
	for (std::deque<std::deque<int> >::iterator it = dequeOfPairs.begin(); it != dequeOfPairs.end(); it++)
	{
		for (std::deque<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque(void)
{
	std::deque<int>::iterator itbegin = _deque.begin();
	std::deque<int>::iterator itend = _deque.end();
	std::cout << "Deque: " ;
	while (itbegin != itend)
	{
		std::cout << *itbegin << " ";
		itbegin++;
	}
	std::cout << std::endl;
}





