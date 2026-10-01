/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:54:53 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/14 17:45:52 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _rates;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool loadDatabase(const std::string& filename);
        float getRate(const std::string& date) const;
        void processInput(const std::string& filename);

        class NoDateException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
