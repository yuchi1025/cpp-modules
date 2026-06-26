/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:18:15 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/25 16:46:41 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap y("YC");
    ClapTrap r("RG");

    std::cout << "=== Basic attack ===" << std::endl;
    y.attack("RG");
    r.takeDamage(2);
    
    std::cout << "=== Repair ===" << std::endl;
    r.beRepaired(3);
    
    std::cout << "=== Take damage ===" << std::endl;
    r.takeDamage(20);
    
    std::cout << "=== Dead ClapTrap cannot act ===" << std::endl;
    r.attack("YC");
    r.beRepaired(42);
    
    std::cout << "=== Use all energy ===" << std::endl;
    for (int i = 0; i < 11; i++)
        y.attack("RG");
    
    std::cout << "=== No energy ===" << std::endl;
    y.attack("RG");
    y.beRepaired(42);
    
    return 0;
}
