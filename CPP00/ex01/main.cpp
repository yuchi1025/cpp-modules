/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:15:16 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/22 13:53:32 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	std::string	command;
	PhoneBook	phonebook;

	(void)argv;
	
	if (argc != 1)
		std::cout << "Usage: ./phonebook" << std::endl;
	else
	{
		while (true)
		{
			std::cout << "Enter one of three commands (ADD/SEARCH/EXIT): ";
			if (!std::getline(std::cin, command))
			{
				std::cout << "EXIT" << std::endl;
				break;
			}
			if (command == "ADD")
				phonebook.addContact();
			else if (command == "SEARCH")
				phonebook.displayContacts();
			else if (command == "EXIT")
				break;
		}
	}
	return 0;
}
