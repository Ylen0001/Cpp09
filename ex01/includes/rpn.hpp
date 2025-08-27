/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:39:18 by oghma             #+#    #+#             */
/*   Updated: 2025/08/27 15:33:11 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "colors.hpp"

class RPN
{
    private :
        std::string _arg;
        std::stack<int> _stack;
        std::stringstream _ss;
    public :
        RPN();
        RPN(std::string arg);
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        bool isValidToken(const std::string& token) const;
        void process();
        bool isOperator(char c) const;
        bool isOperand(char c) const;
};

#endif