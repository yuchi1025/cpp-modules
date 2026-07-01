/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:51:20 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/30 20:37:04 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice")
{
	//std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	//std::cout << "Copy Ice constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	//std::cout << "Ice Copy assignment operator called" << std::endl;
	
    if (this != &other)
		AMateria::operator=(other);
		
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice Destructor called" << std::endl;
}
		
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
