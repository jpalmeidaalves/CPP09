/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:08:12 by joaoalme          #+#    #+#             */
/*   Updated: 2023/11/28 16:08:13 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>

template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack& obj) {*this = obj;};
        ~MutantStack(){};
        
        typedef typename U::iterator iterator;
        iterator begin(void) { return (this->c.begin()); }
        iterator end(void) { return (this->c.end()); }

        MutantStack& operator=(const MutantStack& obj) {
            std::stack<T, U>::operator=(this, obj);
            return (*this);
        }
};

#endif