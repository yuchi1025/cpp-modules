/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:13:20 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/22 13:52:53 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact( void )
{
	//std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact( void )
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

void Contact::setContact( std::string firstName, 
			std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret )
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

static std::string format( std::string str )
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::printContact( int index )
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << format(_firstName) << "|"
			  << std::setw(10) << format(_lastName) << "|"
			  << std::setw(10) << format(_nickname) << "|" << std::endl;
}

void Contact::printContactInfo( void )
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
