/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:59:27 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 15:44:08 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy Animal assignment operator called" << std::endl;
	
    if (this != &other)
		this->type = other.type;
		
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
	//std::cout << "getType member function called" << std::endl;
	
    return this->type;
}
