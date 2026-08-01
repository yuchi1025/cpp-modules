/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:42:30 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/22 11:06:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (this->_signGrade < 1 || this->_executeGrade < 1)
        throw GradeTooHighException();
    if (this->_signGrade > 150 || this->_executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecuteGrade() const
{
    return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form name: " << obj.getName() << std::endl
        << "Signed: " << obj.getSigned() << std::endl
        << "SignGrade: " << obj.getSignGrade() << std::endl
        << "ExecuteGrade: " << obj.getExecuteGrade();
    return out;
}
