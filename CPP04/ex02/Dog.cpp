/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:08:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 19:31:45 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	std::cout << "Default Dog constructor called" << std::endl;
	
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other): AAnimal(other)
{
	std::cout << "Copy Dog constructor called" << std::endl;

	this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy Dog assignment operator called" << std::endl;
	
    if (this != &other)
	{
		AAnimal::operator=(other);
		*this->_brain = *other._brain;
	}
		
    return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;

	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog: Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	//std::cout << "Dog setIdea member function called" << std::endl;
	
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	//std::cout << "Dog getIdea member function called" << std::endl;
	
    return this->_brain->getIdea(index);
}
