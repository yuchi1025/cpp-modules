/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 09:55:00 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/22 13:54:01 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <exception>

template <typename T>
class Array
{
    private:
        T* _elements;
        unsigned int _num;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif
