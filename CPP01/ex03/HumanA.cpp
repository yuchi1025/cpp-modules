/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:51:40 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:47:50 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): name(name), weaponREF(weapon)
{
	std::cout << "HumanA " << this->name << " created" << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << this->weaponREF.getType() << std::endl;
}
