/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:03:42 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/07 16:15:43 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// AB * AP
static Fixed sign( Point const& a, Point const& b, Point const& p)
{
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(a, b, point);
    Fixed d2 = sign(b, c, point);
    Fixed d3 = sign(c, a, point);

    // edge / vertex points
    if ((d1 == Fixed(0)) || (d2 == Fixed(0)) || (d3 == Fixed(0)))
        return false;
    if ((d1 > Fixed(0)) && (d2 > Fixed(0)) && (d3 > Fixed(0)))
        return true; 
    if ((d1 < Fixed(0)) && (d2 < Fixed(0)) && (d3 < Fixed(0)))
        return true; 
    return false;
}

