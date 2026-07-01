/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:25:10 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/30 20:37:21 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "Default MateriaSource constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	//std::cout << "Copy MateriaSource constructor called" << std::endl;
	
    for (int i = 0; i < 4; i++)
	{
		if (other.learned[i])
			this->learned[i] = other.learned[i]->clone();
		else
			this->learned[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	//std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	
    if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->learned[i];
			if (other.learned[i])
				this->learned[i] = other.learned[i]->clone();
			else
				this->learned[i] = NULL;
		}
	}
		
	return *this;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource Destructor called" << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete this->learned[i];
}
		
void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learned[i] == NULL)
		{
			this->learned[i] = m;
			break ;
		}
		
		if (i == 3)
			std::cout << "It's a full learned" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learned[i] && this->learned[i]->getType() == type)
			return this->learned[i]->clone();
	}	
	return NULL;
}
