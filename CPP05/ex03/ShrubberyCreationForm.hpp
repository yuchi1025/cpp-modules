/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:53:37 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/29 16:03:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        std::string getTarget() const;

        void execute(Bureaucrat const& executor) const;

        class FileOpenException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
