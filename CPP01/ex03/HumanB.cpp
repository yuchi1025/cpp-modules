/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:02:54 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:48:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name ): name(name), weaponPTR(NULL)
{
	std::cout << "HumanB " << this->name << " created" << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void HumanB::attack( void )
{
	if (this->weaponPTR != NULL)
		std::cout << this->name << " attacks with their " << (*weaponPTR).getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	weaponPTR = &weapon;
}
