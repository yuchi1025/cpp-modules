/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:01:37 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/16 10:37:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other): _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_stack = other._stack;

    return *this;
}

RPN::~RPN()
{
}

int RPN::calculate(int left, int right, char op)
{
    if (op == '+')
        return left + right;
    if (op == '-')
        return left - right;
    if (op == '*')
        return left * right;
    if (op == '/')
    {
        if (right != 0)
            return left / right;
        else
            throw InvalidExpressionException();
    }
    throw InvalidExpressionException();
}

int RPN::process(const std::string& expression)
{
    for (std::string::size_type i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];

        if (c == ' ')
            continue ;

        if (i + 1 < expression.length() && expression[i + 1] != ' ')
            throw InvalidExpressionException();
        
        if (c >= '0' && c <= '9')
            _stack.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
                throw InvalidExpressionException();
            
            int right = _stack.top();
            _stack.pop();

            int left = _stack.top();
            _stack.pop();

            _stack.push(calculate(left, right, c));
        }
        else
            throw InvalidExpressionException();
    }
    
    if (_stack.size() != 1)
        throw InvalidExpressionException();

    return _stack.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "Invalid Expression";
}
