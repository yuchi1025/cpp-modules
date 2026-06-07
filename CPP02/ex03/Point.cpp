/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:33:33 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/07 15:52:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// A default constructor that initializes x and y to 0
Point::Point( void ): x( 0 ), y( 0 )
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y ): x( x ), y( y )
{
    //std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point( const Point& other ): x( other.x ), y( other.y )
{
    //std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=( const Point& other )
{
    //std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
    {
        // cannot assign const members
    }
    return *this;
}

Point::~Point( void )
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX( void ) const
{
    //std::cout << "getX called" << std::endl;

    return this->x;
}

Fixed Point::getY( void ) const
{
    //std::cout << "getY called" << std::endl;

    return this->y;
}
