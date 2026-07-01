/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:49:36 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/30 20:36:54 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure")
{
	//std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	//std::cout << "Copy Cure constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	//std::cout << "Cure Copy assignment operator called" << std::endl;
	
    if (this != &other)
		AMateria::operator=(other);
		
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure Destructor called" << std::endl;
}
		
AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
