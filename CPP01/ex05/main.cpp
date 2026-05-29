/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:22:58 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:51:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( void )
{
    Harl harl;

    std::cout << "DEBUG: ";
    harl.complain("DEBUG");
    std::cout << "INFO: ";
    harl.complain("INFO");
    std::cout << "WARNING: ";
    harl.complain("WARNING");
    std::cout << "ERROR: ";
    harl.complain("ERROR");
    std::cout << "INVALID: ";
    harl.complain("banana");

    return 0;
}
