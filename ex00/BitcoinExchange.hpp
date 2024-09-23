/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:02:38 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/23 16:46:51 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <cctype>
#include <cstring>

class BitcoinExchange
{
    private:

        std::map<std::string, double> _btcdate; 
    
    public:
    
        BitcoinExchange(std::string input);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &bitcoin);
        ~BitcoinExchange();

        void ValidInput(std::string text);
        void SaveData();
        void ValidLine(std::string line);
        bool ValidDate(std::string date);
    

};

#endif