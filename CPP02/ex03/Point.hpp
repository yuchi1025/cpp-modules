/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:18:45 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/07 15:12:14 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
    public:
        Point( void );
        Point( const float x, const float y );
        Point( const Point& other );
        Point& operator=( const Point& other );
        ~Point( void );

        Fixed getX( void ) const;
        Fixed getY( void ) const;

    private:
       const Fixed x;
       const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
