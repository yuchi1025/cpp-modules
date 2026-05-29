/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:22:58 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:52:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( int argc, char **argv )
{
    Harl harl;

    if (argc != 2)
        std::cout << "Usage: ./harlFilter level" << std::endl;
    else
        harl.complain(std::string(argv[1]));

    return 0;
}
