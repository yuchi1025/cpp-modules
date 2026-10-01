/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:06:54 by yucchen           #+#    #+#             */
/*   Updated: 2026/10/01 16:54:59 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>  // std::ifstream
#include <iostream>
#include <sstream>
#include <cctype>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _rates(other._rates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_rates = other._rates;

    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    // open data.csv
    std::ifstream data_file(filename.c_str());
    
    if (!data_file)
    {
        std::cout << "File open failed!" << std::endl;
        return 0;
    }

    // read every line
    // print every line
    std::string line;
    std::string::size_type comma_pos;
    std::string date;
    std::string rate;
    float f_rate;
    
    // skip header: date,exchange_rate
    std::getline(data_file, line);
    
    while (std::getline(data_file, line))
    {
        comma_pos = line.find(',');
        date = line.substr(0, comma_pos);
        rate = line.substr(comma_pos + 1);

        std::istringstream iss(rate);

        iss >> f_rate;
        
        _rates[date] = f_rate;
    }

    data_file.close();
    
    return 1;
}

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue ;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year;
    int month;
    int day;

    std::istringstream issY(date.substr(0, 4));
    std::istringstream issM(date.substr(5, 2));
    std::istringstream issD(date.substr(8, 2));

    issY >> year;
    issM >> month;
    issD >> day;

    if (month < 1 || month > 12)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (!(day >= 1 && day <= 30))
            return false;
    }
    else if (month == 2)
    {
        if (isLeapYear(year))
        {
            if (!(day >= 1 && day <= 29))
                return false;
        }
        else
        {
            if (!(day >= 1 && day <= 28))
                return false;
        }
    }
    else
    {
        if (!(day >= 1 && day <= 31))
            return false;
    }

    return true;
}

float BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it;

    it = _rates.upper_bound(date);
    if (it == _rates.begin())
        throw NoDateException();

    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream in_file(filename.c_str());
    
    if (!in_file)
    {
        std::cout << "File open failed!" << std::endl;
        return ;
    }

    std::string line;
    std::string::size_type pipe_pos;
    std::string date;
    std::string value;
    float f_value;
    
    std::getline(in_file, line);
    while (std::getline(in_file, line))
    {
        pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos || pipe_pos == 0 || pipe_pos + 1 >= line.length() 
            || line[pipe_pos - 1] != ' ' || line[pipe_pos + 1] != ' ')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }

        date = line.substr(0, pipe_pos - 1);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue ;
        }

        value = line.substr(pipe_pos + 2);

        std::istringstream iss(value);

        if (!(iss >> f_value) || !(iss.eof()))
        {
            std::cout << "Invalid value" << std::endl;
            continue ;
        }

        if (f_value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }

        if (f_value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }

        try
        {
            float rate = getRate(date);
            float result = f_value * rate;
            std::cout << date << " => " << f_value << " = " << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

const char* BitcoinExchange::NoDateException::what() const throw()
{
    return "There is no date <= requested date";
}
