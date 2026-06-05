/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:31:56 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/04 16:20:50 by yucchen          ###   ########.fr       */
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

        // Comparison operators
        bool operator>( const Fixed& other ) const;
        bool operator<( const Fixed& other ) const;
        bool operator>=( const Fixed& other ) const;
        bool operator<=( const Fixed& other ) const;
        bool operator==( const Fixed& other ) const;
        bool operator!=( const Fixed& other ) const;
        
        // Arithmetic operators
        Fixed operator+( const Fixed& other ) const;
        Fixed operator-( const Fixed& other ) const;
        Fixed operator*( const Fixed& other ) const;
        Fixed operator/( const Fixed& other ) const;

        // The 4 increment/decrement (pre-increment:++a and post-increment:a++, pre-decrement:--a and post-decrement:a--) operators
        // Pre-increment ++a
        Fixed& operator++();
        // Post-increment a++
        Fixed operator++(int);
        // Pre-decrement --a
        Fixed& operator--();
        // Post-decrement a--
        Fixed operator--(int);

        // min/max
        static Fixed& min( Fixed& a, Fixed& b );
        static const Fixed& min( const Fixed& a, const Fixed& b);
        static Fixed& max( Fixed& a, Fixed& b );
        static const Fixed& max( const Fixed& a, const Fixed& b);

        Fixed( const int i );
        Fixed( const float f );

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _value;
        static const int _fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif
