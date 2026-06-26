/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:18:15 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/26 09:58:14 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
    FragTrap y("YC");
    FragTrap r("RG");

    std::cout << "=== Basic attack ===" << std::endl;
    y.attack("RG");
    r.takeDamage(2);
    
    std::cout << "=== Repair ===" << std::endl;
    r.beRepaired(3);
    
    std::cout << "=== High Fives Guys ===" << std::endl;
    y.highFivesGuys();

    std::cout << "=== Take damage ===" << std::endl;
    r.takeDamage(200);

    std::cout << "=== Dead FragTrap cannot act ===" << std::endl;
    r.attack("YC");
    r.beRepaired(42);
    r.highFivesGuys();
    
    std::cout << "=== Use all energy ===" << std::endl;
    for (int i = 0; i < 101; i++)
        y.attack("RG");
    
    std::cout << "=== No energy ===" << std::endl;
    y.attack("RG");
    y.beRepaired(42);
    y.highFivesGuys();
    
    return 0;
}
