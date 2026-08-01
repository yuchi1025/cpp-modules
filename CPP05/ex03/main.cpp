/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:49:45 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 17:23:41 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(NULL));

    Intern intern;

    AForm* form1 = intern.makeForm("shrubbery creation", "home");

    Bureaucrat y("Yuchi", 1);
    
    if (form1)
    {
        y.signForm(*form1);
        y.executeForm(*form1);

        delete form1;
    }

    AForm* form2 = intern.makeForm("robotomy request", "Bender");

    if (form2)
    {
        y.signForm(*form2);
    
        for (int i = 0; i < 5; i++)
            y.executeForm(*form2);

        delete form2;
    }

    AForm* form3 = intern.makeForm("presidential pardon", "Remi");

    if (form3)
    {
        y.signForm(*form3);
        y.executeForm(*form3);

        delete form3;
    }

    AForm* form4 = intern.makeForm("invalid", "test");

    if (form4 == NULL)
        std::cout << "Invalid form" << std::endl;

    return 0;
}
