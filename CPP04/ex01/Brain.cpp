/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:56:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 16:03:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Init idea";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy Brain assignment operator called" << std::endl;
	
    if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}

    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return ;
	
	//std::cout << "setIdea member function called" << std::endl;
	
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "";
	
	//std::cout << "getIdea member function called" << std::endl;
	
    return this->ideas[index];
}
