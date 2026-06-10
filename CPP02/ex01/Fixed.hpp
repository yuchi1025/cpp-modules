/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:31:56 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/08 16:00:17 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    public:
        // Default constructor
        Fixed( void );
        // Copy constructor
        Fixed( const Fixed& other );
        // A copy assignment operator overload
        Fixed& operator=( const Fixed& other );
        // Destructor
        ~Fixed( void );
        // A constructor that takes a constant integer as a parameter
        Fixed( const int i );
        // A constructor that takes a constant floating-point number as a parameter
        Fixed( const float f );

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _value;
        static const int _fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& o, const Fixed& i );

#endif
