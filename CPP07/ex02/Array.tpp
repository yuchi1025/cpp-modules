/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 13:56:03 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/23 15:22:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>   // NULL
#include <exception>

template <typename T>
Array<T>::Array(): _elements(NULL), _num(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _num(n)
{
}

template <typename T>
Array<T>::Array(const Array& other): _elements(NULL), _num(other._num)
{
    if (this->_num > 0)
    {
        this->_elements = new T[this->_num]();
        for (unsigned int i = 0; i < this->_num; i++)
            this->_elements[i] = other._elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] this->_elements;

        this->_num = other._num;
        if (this->_num > 0)
        {
            this->_elements = new T[this->_num]();
            for (unsigned int i = 0; i < this->_num; i++)
                this->_elements[i] = other._elements[i];
        }
        else
            this->_elements = NULL;
    }

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _elements;
}

// operator[]
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_num)
        throw OutOfBoundsException();
    return this->_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_num)
        throw OutOfBoundsException();
    return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_num;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "Array index out of bounds!";
}
