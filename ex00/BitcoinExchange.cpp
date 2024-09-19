/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:26:56 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/19 17:11:59 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input)
{
    SaveDate();
    (void)input;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    (void)copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoin)
{
    (void)bitcoin;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::SaveDate()
{
    std::ifstream inFile("data.csv");
    if(!inFile.is_open())
        throw "Error: Unable to open data file";
    std::string line;
    while(std::getline (inFile, line))
    {
        size_t pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string value_str = line.substr(pos+1);
        double value;
        std::istringstream iss(value_str);
        iss >> value;

        _btcdate[date] = value;
    }
    //std::cout << _btcdate["2009-01-29"] << std::endl;
}

// void BitcoinExchange::Value(char *text)
// {
//     try
//     {
//         BitcoinExchange::SaveDate();
//         std::cout << _btcdate["2009-01-29"] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
// }