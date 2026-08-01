/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:49:45 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 15:41:43 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "=== Success ===" << std::endl;
    Bureaucrat y("Yuchi", 1);
    ShrubberyCreationForm form("form");
    PresidentialPardonForm form1("form1");

    y.signForm(form);

    ShrubberyCreationForm copy(form);
    
    std::cout << form << std::endl;
    std::cout << copy << std::endl;

    y.executeForm(form);
    y.executeForm(copy);
    y.signForm(form1);
    y.executeForm(form1);

    std::cout << "=== Unsigned form ===" << std::endl;
    ShrubberyCreationForm form2("form2");
    RobotomyRequestForm form3("form3");

    y.executeForm(form2);
    y.executeForm(form3);

    std::cout << "=== Shrubbery: sign grade too low ===" << std::endl;
    Bureaucrat r("Remi", 146);
    
    r.signForm(form2);
    std::cout << form2 << std::endl;

    std::cout << "=== Can sign, cannot execute ===" << std::endl;
    Bureaucrat m("Mark", 142);
    Bureaucrat j("John", 60);
    Bureaucrat g("George", 20);
    RobotomyRequestForm form4("form4");
    PresidentialPardonForm form5("form5");

    m.signForm(form2);
    m.executeForm(form2);
    j.signForm(form4);
    j.executeForm(form4);
    g.signForm(form5);
    g.executeForm(form5);

    std::cout << "=== Robotomy: repeated attempts === " << std::endl;
    RobotomyRequestForm form6("form6");

    y.signForm(form6);
    
    for (int i = 0; i < 10; i++)
        y.executeForm(form6);

    std::cout << "=== Polymorphism with references ===" << std::endl;
    ShrubberyCreationForm shrubbery("shrubbery");
    RobotomyRequestForm robotomy("robotomy");
    PresidentialPardonForm presidential("presidential");

    AForm& s_form = shrubbery;
    AForm& r_form = robotomy;
    AForm& p_form = presidential;

    y.signForm(s_form);
    y.signForm(r_form);
    y.signForm(p_form);

    y.executeForm(s_form);
    y.executeForm(r_form);
    y.executeForm(p_form);
    
    std::cout << "=== Virtual destructor ===" << std::endl;
    AForm* form7 = new ShrubberyCreationForm("new");

    delete form7;

    std::cout << "=== Assignment operator ===" << std::endl;
    ShrubberyCreationForm first("first");
    ShrubberyCreationForm second("second");

    y.signForm(first);
    second = first;

    std::cout << first << std::endl;
    std::cout << "First target: " << first.getTarget() << std::endl;
    std::cout << second << std::endl;
    std::cout << "Second target: " << second.getTarget() << std::endl;

    return 0;
}
