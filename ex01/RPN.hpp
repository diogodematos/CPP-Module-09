/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:14:06 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 14:50:02 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <algorithm>

class RPN
{
    private:
        
        std::stack<int> _numbers;
        std::stack<char> _signal;

    public:
    
        RPN();
        RPN(std::string expression);
        RPN(const RPN &copy);
        RPN &operator=(const RPN &rpn);
        ~RPN();

        void ValidInput(std::string);
        int Operation();

        class WrongInput : public std::exception {
             public:
                virtual const char* what() const throw();
        };
    
};

#endif