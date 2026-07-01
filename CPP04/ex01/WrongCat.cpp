/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:08:31 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 15:45:15 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy WrongCat assignment operator called" << std::endl;

    if (this != &other)
        WrongAnimal::operator=(other);
    
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow!" << std::endl;
}
