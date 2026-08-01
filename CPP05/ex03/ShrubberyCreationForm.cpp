/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:03:49 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 15:59:47 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    // check signed
    if (!this->getSigned())
        throw FormNotSignedException();
    
    // check executor grade
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    
    // perform shrubbery action
    std::ofstream file((this->_target + "_shrubbery").c_str());

    if (!file.is_open())
        throw FileOpenException();

    file << "  *" << std::endl;
    file << " ***" << std::endl;
    file << "*****" << std::endl;
    file << "  |" << std::endl;
    
    file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Cannot create shrubbery file";
}
