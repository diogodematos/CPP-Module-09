/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:04:56 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/26 17:38:53 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input)
{
    try
    {
        ValidInput(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

RPN::RPN(const RPN &copy) : _numbers(copy._numbers), _signal(copy._signal){}

RPN &RPN::operator=(const RPN &rpn)
{
    if (this != &rpn)
    {
        _numbers = rpn._numbers;
        _signal = rpn._signal;
    }
    return *this;
}

RPN::~RPN(){}

void RPN::ValidInput(std::string input)
{
    if (input.size() == 0)
        throw WrongInput();
    for(unsigned int i = 0; i < input.size(); i++)
    {
        while (i == 32)
            i++;
        if(input[i] >= 48 && input[i] <= 57 && input[i+1] != 32 && i < input.size() -1)
        throw WrongInput();
        if ((input[i] == 42 || input[i] == 43 || input[i] == 45 || input[i] == 47) && input[i + 1] != 32 && i < input.size() -1)
        throw WrongInput();
    }
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    for(unsigned int i = 0; i < input.size(); i++)
    {
        if(input[i] >= 48 && input[i] <= 57)
            _numbers.push(input[i] - 48);
        if (input[i] == 42 || input[i] == 43 || input[i] == 45 || input[i] == 47)
            _signal.push(input[i]);
        if (_numbers.size() <= _signal.size())
        throw WrongInput();
        if (!(_numbers.size() >= 2 && _signal.size() >= 1) && i == input.size()-1)
            throw WrongInput();
        if (_numbers.size() >= 2 && _signal.size() >= 1)
            _numbers.push(Operation());
    }
    if ((_numbers.size() != 1 || _signal.size() != 0))
            throw WrongInput();
    std::cout << _numbers.top() << std::endl;
}

int RPN::Operation()
{
    int r, t, t2;
    char o;
    t = _numbers.top();
    _numbers.pop();
    t2 = _numbers.top();
    _numbers.pop();
    o = _signal.top();
    _signal.pop();
    switch (o)
    {
        case '+':
            r = t2 + t;
            break;
        case '-':
            r = t2 - t;
            break;
        case '*':
            r = t2 * t;
            break;
        case '/': 
            if (t == 0)
                throw WrongInput();
            r = t2 / t;
            break;
    }
    return r;
}

const char* RPN::WrongInput::what() const throw()
{
    return ("Error");
}