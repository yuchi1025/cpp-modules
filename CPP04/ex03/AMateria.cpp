/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:57:48 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/30 20:36:36 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): _type("")
{
	//std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	//std::cout << "Parameterized AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	//std::cout << "Copy AMateria constructor called" << std::endl;
	
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	//std::cout << "AMateria Copy assignment operator called" << std::endl;
	
    if (this != &other)
		this->_type = other._type;
		
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	
	//std::cout << "AMateria use member function called" << std::endl;
}
