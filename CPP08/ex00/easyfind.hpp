/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:50:52 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/04 18:06:24 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <exception>
#include <algorithm>

class NotFoundException: public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found!";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFoundException();

    return it;
}

#endif
