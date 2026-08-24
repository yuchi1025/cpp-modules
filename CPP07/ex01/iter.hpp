/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:28:06 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/21 11:43:31 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstddef> // std::size_t

template <typename T, typename F>
void iter(T *arr, const std::size_t len, F function)
{
    for (std::size_t i = 0; i < len; i++)
        function(arr[i]);
}

#endif
