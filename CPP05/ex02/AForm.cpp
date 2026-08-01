/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:42:30 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 15:54:11 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (this->_signGrade < 1 || this->_executeGrade < 1)
        throw GradeTooHighException();
    if (this->_signGrade > 150 || this->_executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "AForm name: " << obj.getName() << std::endl
        << "Signed: " << obj.getSigned() << std::endl
        << "SignGrade: " << obj.getSignGrade() << std::endl
        << "ExecuteGrade: " << obj.getExecuteGrade();
    return out;
}
