/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 12:21:42 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/07 13:39:16 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>      // std::srand
#include <ctime>        // std::time
#include "identify.hpp"

int main()
{
    std::srand(std::time(NULL));

    Base* base = generate();

    identify(base);
    identify(*base);

    delete base;

    return 0;
}
