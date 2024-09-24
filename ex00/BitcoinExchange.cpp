/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:26:56 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:27 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string input)
{
    try
    {
        SaveData();
        ValidInput(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _btcdate(copy._btcdate){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoin)
{
    if (this != &bitcoin)
        _btcdate = bitcoin._btcdate;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::SaveData()
{
    std::ifstream inFile("data.csv");
    if(!inFile.is_open())
        throw WrongFile();
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
}

void BitcoinExchange::ValidInput(std::string input)
{
    std::ifstream inFile(input.c_str());
    if(!inFile.is_open())
        throw WrongFile();
    std::string line;
    if (!std::getline(inFile, line))
		return ;
    if (line != "date | value")
    {
        std::cerr <<  "Error: bad input => " << line << std::endl;
        return ;
    }
    while(std::getline (inFile, line))
        ValidLine(line);
}

void BitcoinExchange::ValidLine(std::string line)
{
    if (line.size() < 14) // min length = 14
    {
        std::cerr <<  "Error: bad input => " << line << std::endl; 
        return ;
    }
    int pipe = 0;
    int sub = 0;
    for (unsigned int i = 0; i < line.size(); i++)
    {    
        if (line[i] == '|')
            pipe++;
        if (line[i] == '-')
            sub++;
    }
    if (line[10] != 32 || line[11] != '|' || line[12] != 32 || pipe != 1)
    {
        std::cerr <<  "Error: bad input => " << line << std::endl;
        return ;
    }
    std::string date = line.substr(0, 10);
    std::string value = line.substr(13);
    if (!ValidDate(date))
        {
            std::cerr <<  "Error: bad input => " << line << std::endl;
            return;
        }
    else
    {
        unsigned int i = 0, point = 0;
        if(value[i] == '-')
            i++;   
        while(i < value.size())
        {   if (value[i] == '.')
                point++;
            if (!isdigit(value[i]) || point > 1)
            {
                std::cerr <<  "Error: bad input => " << line << std::endl;
                return ;
            }
            i++;
        }
        double val;
        val = std::strtod(value.c_str(), NULL);
        if (val < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return;
        }
        else if (val > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            return ;
        }
        else
        {
            std::map<std::string, double>::iterator it = _btcdate.find(date);
            if (it != _btcdate.end())
            {
                std::cout << date << " => " << value << " = " << val*it->second << std::endl;
                return ;
            }
            it = _btcdate.lower_bound(date);
            --it;
            std::cout << date << " => " << value << " = " << val*it->second << std::endl;
        }
    }
}

bool LeapYear(int year)
{
    return (year %4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::ValidDate(std::string date)
{
    if (date[4] != '-' && date[7] != '-')
        return false;
    int year, month, day;
    char y, m;
    std::istringstream iss(date);
    if (!(iss >> year >> y >> month >> m >> day))
        return false;
    if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        return false;
    if (month < 1 || month > 12)
        return false;
    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && LeapYear(year))
        daysMonth[1] = 29;
    if (day < 1 || day > daysMonth[month - 1])
        return false;
    return true;
}

const char* BitcoinExchange::WrongFile::what() const throw()
{
    return ("Error: Unable to open data file");
}