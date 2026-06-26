/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:18:15 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/26 12:50:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap y("YC");
    DiamondTrap r("RG");

    std::cout << "=== whoAmI ===" << std::endl;
    y.whoAmI();
    r.whoAmI();

    std::cout << "=== DiamondTrap(ScavTrap) attack ===" << std::endl;
    y.attack("RG");
    r.takeDamage(2);
    
    std::cout << "=== Repair ===" << std::endl;
    r.beRepaired(3);
    
    std::cout << "=== Gate keeper mode ===" << std::endl;
    r.guardGate();
    
    std::cout << "=== High Fives Guys ===" << std::endl;
    y.highFivesGuys();

    std::cout << "=== Take damage ===" << std::endl;
    r.takeDamage(200);

    std::cout << "=== Dead DiamondTrap cannot act ===" << std::endl;
    r.attack("YC");
    r.beRepaired(42);
    r.guardGate();
    r.highFivesGuys();
    r.whoAmI();
    
    std::cout << "=== Use all energy ===" << std::endl;
    for (int i = 0; i < 51; i++)
        y.attack("RG");
    
    std::cout << "=== No energy ===" << std::endl;
    y.attack("RG");
    y.beRepaired(42);
    y.guardGate();
    y.highFivesGuys();
    y.whoAmI();
    
    return 0;
}
