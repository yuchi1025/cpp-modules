/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:28:12 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:49:14 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type)
{
	std::cout << "Weapon: " << this->type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

const std::string& Weapon::getType( void ) const
{
	return this->type;
}

void Weapon::setType( std::string type )
{
	this->type = type;
}
