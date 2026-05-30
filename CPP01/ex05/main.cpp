/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:22:58 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/30 13:35:34 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( void )
{
    Harl harl;

    std::cout << std::endl;

    std::cout << "DEBUG: ";
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "INFO: ";
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "WARNING: ";
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "ERROR: ";
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "INVALID: ";
    harl.complain("banana");
    std::cout << std::endl;

    return 0;
}
