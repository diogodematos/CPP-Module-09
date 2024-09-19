/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:02:38 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/19 16:00:09 by dcarrilh         ###   ########.fr       */
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

class BitcoinExchange
{
    private:

        std::map<std::string, double> _btcdate; 
    
    public:
    
        BitcoinExchange(std::string input);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &bitcoin);
        ~BitcoinExchange();

        void Value(char *text);
        void SaveDate();
    

};

#endif