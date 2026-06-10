/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:18:45 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/10 10:26:16 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
    public:
        // Default constructor
        Point( void );
        Point( const float x, const float y );
        // Copy constructor
        Point( const Point& other );
        // A copy assignment operator overload
        Point& operator=( const Point& other );
        // Destructor
        ~Point( void );

        Fixed getX( void ) const;
        Fixed getY( void ) const;

    private:
       const Fixed x;
       const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
