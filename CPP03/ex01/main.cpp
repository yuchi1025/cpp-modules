/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:18:15 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/25 18:05:52 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main()
{
    ScavTrap y("YC");
    ScavTrap r("RG");

    std::cout << "=== ScavTrap attack ===" << std::endl;
    y.attack("RG");
    r.takeDamage(2);
    
    std::cout << "=== Repair ===" << std::endl;
    r.beRepaired(3);

    std::cout << "=== Gate keeper mode ===" << std::endl;
    r.guardGate();
    
    std::cout << "=== Take damage ===" << std::endl;
    r.takeDamage(200);
    
    std::cout << "=== Dead ScavTrap cannot act ===" << std::endl;
    r.attack("YC");
    r.beRepaired(42);
    r.guardGate();
    
    std::cout << "=== Use all energy ===" << std::endl;
    for (int i = 0; i < 51; i++)
        y.attack("RG");
    
    std::cout << "=== No energy ===" << std::endl;
    y.attack("RG");
    y.beRepaired(42);
    y.guardGate();
    
    return 0;
}
