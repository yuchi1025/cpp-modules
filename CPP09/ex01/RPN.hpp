/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:26:19 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/16 11:17:29 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <stack>
#include <string>
#include <exception>

class RPN
{
    private:
        std::stack<int> _stack;

        int calculate(int left, int right, char op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int process(const std::string& expression);

        class InvalidExpressionException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
