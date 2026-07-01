/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:45:34 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 19:31:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(): AAnimal()
{
	std::cout << "Default Cat constructor called" << std::endl;

	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other): AAnimal(other)
{
	std::cout << "Copy Cat constructor called" << std::endl;

	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy Cat assignment operator called" << std::endl;

    if (this != &other)
    {
		AAnimal::operator=(other);
		*this->_brain = *other._brain;
	}
	
    return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;

	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat: Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	//std::cout << "Cat setIdea member function called" << std::endl;
	
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	//std::cout << "Cat getIdea member function called" << std::endl;
	
    return this->_brain->getIdea(index);
}
