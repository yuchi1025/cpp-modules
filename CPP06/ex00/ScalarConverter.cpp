/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:45:46 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/08 16:41:06 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>  // std::isdigit, std::isprint
#include <cstdlib> // std::strtod
#include <climits> // INT_MIN, INT_MAX, CHAR_MIN, CHAR_MAX
#include <cmath>   // std::floor
#include <iomanip> // std::setprecision
#include "ScalarConverter.hpp"

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

bool isPseudoLiteral(const std::string& literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf" || literal == "nan");
}

bool isIntLiteral(const std::string& literal)
{
    size_t i = 0;

    if (literal.empty())
        return false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    if (i == literal.length())
        return false;

    while (i < literal.length())
    {
        if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return false;
        i++;
    }

    return true;
}

bool isFloatLiteral(const std::string& literal)
{
    size_t i = 0;
    int point_cnt = 0;
    int digit_cnt = 0;

    if (literal.length() < 2)
        return false;

    if (literal[literal.length() - 1] != 'f')
        return false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < literal.length() - 1)
    {
        if (std::isdigit(static_cast<unsigned char>(literal[i])))
            digit_cnt++;
        else if (literal[i] == '.')
        {
            point_cnt++;
            if (point_cnt > 1)
                return false;
        }
        else
            return false;
        i++;
    }

    if (digit_cnt == 0 || point_cnt != 1)
        return false;

    return true;
}

bool isDoubleLiteral(const std::string& literal)
{
    size_t i = 0;
    int point_cnt = 0;
    int digit_cnt = 0;
    
    if (literal.empty())
        return false;
        
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < literal.length())
    {
        if (std::isdigit(static_cast<unsigned char>(literal[i])))
            digit_cnt++;
        else if (literal[i] == '.')
        {
            point_cnt++;
            if (point_cnt > 1)
                return false;
        }
        else
            return false;
        i++;
    }

    if (digit_cnt == 0 || point_cnt != 1)
        return false;

    return true;
}

LiteralType checkType(const std::string& literal)
{
    if (isPseudoLiteral(literal))
        return PSEUDO;

    if (literal.length() == 1 
        && !std::isdigit(static_cast<unsigned char>(literal[0]))
        && std::isprint(static_cast<unsigned char>(literal[0])))
        return CHAR;
    
    if (isIntLiteral(literal))
        return INT;

    if (isFloatLiteral(literal))
        return FLOAT;

    if (isDoubleLiteral(literal))
        return DOUBLE;

    return INVALID;
}

void printPseudo(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "nanf" || literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void printChar(double value)
{
    if (value < static_cast<double>(CHAR_MIN) || value > static_cast<double>(CHAR_MAX))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c_value = static_cast<char>(value);

    if (!std::isprint(static_cast<unsigned char>(c_value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c_value << "'" << std::endl;
}

void printInt(double value)
{
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    int i_value = static_cast<int>(value);

    std::cout << "int: " << i_value << std::endl;
}

void printFloat(float value)
{
    std::cout << std::setprecision(7);
    std::cout << "float: " << value;

    if (std::floor(value) == value)
        std::cout << ".0";
        
    std::cout << "f" << std::endl;
}

void printDouble(double value)
{
    std::cout << std::setprecision(15);
    std::cout << "double: " << value;

    if (std::floor(value) == value)
        std::cout << ".0";
    
    std::cout << std::endl;
}

void convertChar(const std::string& literal)
{
    char c_value = literal[0];
    double d_value = static_cast<double>(c_value);
    float f_value = static_cast<float>(c_value);

    printChar(d_value);
    printInt(d_value);
    printFloat(f_value);
    printDouble(d_value);
}

void convertInt(const std::string& literal)
{
    double d_value = std::strtod(literal.c_str(), NULL);
    float f_value = static_cast<float>(d_value);

    printChar(d_value);
    printInt(d_value);
    printFloat(f_value);
    printDouble(d_value);
}

void convertFloat(const std::string& literal)
{
    std::string numberPart = literal.substr(0, literal.length() - 1);
    double parsed_value = std::strtod(numberPart.c_str(), NULL);
    float f_value = static_cast<float>(parsed_value);
    double d_value = static_cast<double>(f_value);
    
    printChar(d_value);
    printInt(d_value);
    printFloat(f_value); 
    printDouble(d_value);
}

void convertDouble(const std::string& literal)
{
    double d_value = std::strtod(literal.c_str(), NULL);
    float f_value = static_cast<float>(d_value);

    printChar(d_value);
    printInt(d_value);
    printFloat(f_value);
    printDouble(d_value);
}

void ScalarConverter::convert(const std::string& literal) 
{
    LiteralType type = checkType(literal);

    if (type == PSEUDO)
        printPseudo(literal);
    else if (type == CHAR)
        convertChar(literal);
    else if (type == INT)
        convertInt(literal);
    else if (type == FLOAT)
        convertFloat(literal);
    else if (type == DOUBLE)
        convertDouble(literal);
    else
        std::cout << "Invalid literal" << std::endl;
}
