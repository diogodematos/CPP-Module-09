/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:59:10 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/23 14:37:06 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        std::cerr << "Wrong input!" << std::endl;
    else
        BitcoinExchange btcex(argv[1]);
    return (0);
}