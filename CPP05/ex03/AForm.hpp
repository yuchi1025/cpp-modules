/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:11:26 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/26 15:03:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;

    public:
        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& other);

        virtual void execute(Bureaucrat const& executor) const = 0;

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

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

// << operator
std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
