/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:19:24 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/01 13:44:34 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): _name("")
{
	//std::cout << "Default Character constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	//std::cout << "Parameterized Character constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& other): _name(other._name)
{
	//std::cout << "Copy Character constructor called" << std::endl;
	
    for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	//std::cout << "Character Copy assignment operator called" << std::endl;
	
    if (this != &other)
	{
		this->_name = other._name;
		
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
		
	return *this;
}

Character::~Character()
{
	//std::cout << "Character Destructor called" << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
		
		if (i == 3)
			std::cout << "It's a full inventory" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid index: " << idx << std::endl;
		return ;
    }
		
	if (this->inventory[idx] == NULL)
	{
		std::cout << "Non-existent Materia" << std::endl;
		return ;
	}
	
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid index: " << idx << std::endl;
		return ;
    }
		
	if (this->inventory[idx] == NULL)
		std::cout << "Non-existent Materia" << std::endl;
	else
		this->inventory[idx]->use(target);
}
