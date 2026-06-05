/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:55:37 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/03 11:24:36 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// A default constructor that initializes the fixed-point number value to 0
Fixed::Fixed( void ): _value( 0 )
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

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

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int i ): _value( i * (1 << _fractionalBits) )
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ): _value( roundf(f * (1 << _fractionalBits)) )
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->_value / (1 << _fractionalBits);
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

std::ostream& operator<<( std::ostream& o, Fixed const& i )
{
   o << i.toFloat();
   return o;
}
