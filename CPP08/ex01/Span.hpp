/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:09:52 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/03 14:23:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int _max;
        std::vector<int> _numbers;

    public:
        Span();
        explicit Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);

        template <typename Iter>
        void addNumbers(Iter begin, Iter end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                ++begin;
            }
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class AlreadyNException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
