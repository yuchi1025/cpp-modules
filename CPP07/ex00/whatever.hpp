/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:31:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/20 17:46:46 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b)
{
    if (a >= b)
        return b;
    else
        return a;
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif
