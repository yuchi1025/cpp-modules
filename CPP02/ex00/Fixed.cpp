/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:55:37 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/08 14:32:22 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// A default constructor that initializes the fixed-point number value to 0
Fixed::Fixed( void ): _value( 0 )
{
    std::cout << "Default constructor called" << std::endl;
}

// A copy constructor
Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// A copy assignment operator overload
Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
    {
        // Copy member variables
        this->_value = other.getRawBits();
    }

    return *this;
}

// A destructor
Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}
