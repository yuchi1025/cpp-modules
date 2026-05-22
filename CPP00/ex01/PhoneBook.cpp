/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:52:06 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/22 13:54:16 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	//std::cout << "Constructor called" << std::endl;
	
	_count = 0;
	
	return;
}

PhoneBook::~PhoneBook( void )
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

static bool	checkEmpty( std::string	str )
{
	if (str.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return true;
	}
	return false;
}

void	PhoneBook::addContact( void )
{
	std::string	firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First name: ";
	if (!std::getline(std::cin, firstName))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}
	if (checkEmpty( firstName ))
		return;
	std::cout << "Last name: ";
	if (!std::getline(std::cin, lastName))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}
	if (checkEmpty( lastName ))
		return;
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nickname))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}
	if (checkEmpty( nickname ))
		return;
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phoneNumber))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}
	if (checkEmpty( phoneNumber ))
		return;
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, darkestSecret))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}
	if (checkEmpty( darkestSecret ))
		return;
	
	_contacts[_count % 8].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_count++;
}

void	PhoneBook::displayContacts( void )
{
	int 		cnt;
	std::string	i_info;
	int			index;

	if (_count >= 8)
		cnt = 8;
	else
		cnt = _count;
	
	if (cnt == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname"<< "|" << std::endl;
	
	for (int i = 0; i < cnt; i++)
		_contacts[i].printContact(i);
	
	std::cout << "Enter index to display info: ";
	
	if (!std::getline(std::cin, i_info))
	{
		std::cout << "EXIT" << std::endl;
		return;
	}

	std::istringstream iss(i_info);
	
	if (!(iss >> index) || !iss.eof() || index < 0 || index >= cnt)
		std::cout << "Invalid input" << std::endl;
	else
		_contacts[index].printContactInfo();
}
