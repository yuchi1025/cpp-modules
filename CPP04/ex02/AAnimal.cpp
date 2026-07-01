/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:59:27 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 19:29:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Copy AAnimal assignment operator called" << std::endl;
	
    if (this != &other)
		this->type = other.type;
		
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	//std::cout << "getType member function called" << std::endl;
	
    return this->type;
}
