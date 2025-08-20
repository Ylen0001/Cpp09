/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <oghma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:39:18 by oghma             #+#    #+#             */
/*   Updated: 2025/08/20 17:53:12 by oghma            ###   ########.fr       */
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

using namespace std;
class RPN
{
    private :
        string _arg;
        stack<int> _stack;
        stringstream _ss;
    public :
        RPN();
        RPN(string arg);
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        bool isValidToken(const std::string& token) const;
        void process();
        bool isOperator(char c) const;
        bool isOperand(char c) const;
};

#endif