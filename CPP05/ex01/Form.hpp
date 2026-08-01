/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:11:26 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/21 10:31:11 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;

    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& other);

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

// << operator
std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
