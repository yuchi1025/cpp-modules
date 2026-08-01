/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:28:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 17:28:54 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string names[3];

    names[0] = "shrubbery creation";
    names[1] = "robotomy request";
    names[2] = "presidential pardon";

    int name_index = -1;

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            name_index = i;
            break;
        }
    }

    switch (name_index)
    {
        case 0:
            std::cout << "Intern creates a shrubbery form" << std::endl; 
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates a robotomy form" << std::endl; 
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates a presidential form" << std::endl; 
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern cannot create " << name << std::endl; 
            return NULL;
    }
}

