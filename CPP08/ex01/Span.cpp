/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:52:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/07 11:20:42 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Span.hpp"

Span::Span(): _max(0)
{
}

Span::Span(unsigned int N): _max(N)
{
}

Span::Span(const Span& other): _max(other._max), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_max = other._max;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (_numbers.size() == this->_max)
        throw AlreadyNException();
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = this->_numbers;

    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = longestSpan();

    unsigned int distance;
    for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); ++it)
    {
        distance = static_cast<unsigned int>(*it) - static_cast<unsigned int>(*(it - 1));

        if (distance < shortest)
            shortest = distance;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    std::vector<int>::const_iterator maxInt = std::max_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator minInt = std::min_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(*maxInt) - static_cast<unsigned int>(*minInt);
}

const char* Span::AlreadyNException::what() const throw()
{
    return "Already MAX elements";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No Span";
}
