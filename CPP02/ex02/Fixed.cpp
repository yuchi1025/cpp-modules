/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:55:37 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/04 16:29:15 by yucchen          ###   ########.fr       */
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

// Comparison operators
bool Fixed::operator>( const Fixed& other ) const
{
    std::cout << "> operator called" << std::endl;
    
    return (this->_value > other._value);
}

bool Fixed::operator<( const Fixed& other ) const
{
    std::cout << "< operator called" << std::endl;
    
    return (this->_value < other._value);
}

bool Fixed::operator>=( const Fixed& other ) const
{
    std::cout << ">= operator called" << std::endl;
    
    return (this->_value >= other._value);
}

bool Fixed::operator<=( const Fixed& other ) const
{
    std::cout << "<= operator called" << std::endl;
    
    return (this->_value <= other._value);
}

bool Fixed::operator==( const Fixed& other ) const
{
    std::cout << "== operator called" << std::endl;
    
    return (this->_value == other._value);
}

bool Fixed::operator!=( const Fixed& other ) const
{
    std::cout << "!= operator called" << std::endl;
    
    return (this->_value != other._value);
}

// Arithmetic operators
Fixed Fixed::operator+( const Fixed& other ) const
{
    Fixed result;

    std::cout << "+ operator called with " << this->_value;
    std::cout << " and " << other.getRawBits() << std::endl;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-( const Fixed& other ) const
{
    Fixed result;

    std::cout << "- operator called with " << this->_value;
    std::cout << " and " << other.getRawBits() << std::endl;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*( const Fixed& other ) const
{
    std::cout << "* operator called with " << this->_value;
    std::cout << " and " << other.getRawBits() << std::endl;

    return Fixed( this->toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( const Fixed& other ) const
{
    std::cout << "/ operator called with " << this->_value;
    std::cout << " and " << other.getRawBits() << std::endl;

    return Fixed( this->toFloat() / other.toFloat() );
}

// Increment / Decrement
// Pre-increment ++a
Fixed& Fixed::operator++()
{
    std::cout << "Pre-increment operator called" << std::endl;
    // increase first
    (this->_value)++;
    return *this;
}

// Post-increment a++
// int parameter is just a dummy marker so C++ can distinghish a++ from ++a
Fixed Fixed::operator++(int)
{
    std::cout << "Post-increment operator called" << std::endl;
    Fixed temp(*this);
    // increase current object
    (this->_value)++;
    return temp;
}

// Pre-decrement --a
Fixed& Fixed::operator--()
{
    std::cout << "Pre-decrement operator called" << std::endl;
    // decrease first
    (this->_value)--;
    return *this;
}

// Post-decrement a--
// int parameter is just a dummy marker so C++ can distinghish a-- from --a
Fixed Fixed::operator--(int)
{
    std::cout << "Post-decrement operator called" << std::endl;
    Fixed temp(*this);
    // decrease current object
    (this->_value)--;
    return temp;
}

// min/max
Fixed& Fixed::min( Fixed& a, Fixed& b)
{
    std::cout << "min with normal objecrs called" << std::endl;
    if (a > b)
        return b;
    return a;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b)
{
    std::cout << "min with const objecrs called" << std::endl;
    if (a > b)
        return b;
    return a;
}

Fixed& Fixed::max( Fixed& a, Fixed& b)
{
    std::cout << "max with normal objecrs called" << std::endl;
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b)
{
    std::cout << "max with const objecrs called" << std::endl;
    if (a > b)
        return a;
    return b;
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
