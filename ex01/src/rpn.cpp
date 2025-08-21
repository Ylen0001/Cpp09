/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:45:16 by oghma             #+#    #+#             */
/*   Updated: 2025/08/21 15:12:26 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rpn.hpp"

RPN::RPN(){}
RPN::RPN(string arg) : _arg(arg){}
RPN::RPN(const RPN &other)
{
    this->_arg = other._arg;
    this->_stack = other._stack;
}
RPN& RPN::operator=(const RPN &other)
{
    if(this != &other) // auto-assignement check
    {
        this->_arg = other._arg;
        this->_stack = other._stack;
    }
    return *this;
};

RPN::~RPN(){
    while (!_stack.empty())
        _stack.pop();
    _arg.clear();
}

bool RPN::isValidToken(const std::string& token) const
{
    return token.length() == 1 && (isOperator(token[0]) || isOperand(token[0]));
}


bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isOperand(char c) const
{
    return isdigit(c);
}


void RPN::process()
{
    
    for (size_t i = 0; i < _arg.size(); ++i) {
        char c = _arg[i];
        if (!isOperator(c) && !isOperand(c) && c != ' ') 
			throw runtime_error(string("invalid character '") + c + "'");
        // Si un opérande ou opérateur est collé au suivant
        if ((isOperator(c) || isOperand(c)) && i + 1 < _arg.size() && _arg[i+1] != ' ')
			throw runtime_error("Error: missing space between token");
    }

    std::stringstream ss(_arg);
    std::string token;

    while (ss >> token) {
        if (!isValidToken(token))
			throw runtime_error(string("invalid token '") + token + "'");

        char c = token[0];

        if (isOperand(c)) {
            _stack.push(c - '0');  // conversion char -> int
        } else { // opérateur
            if (_stack.size() < 2) {
				throw runtime_error("Error: not enough operands for operator");

            }

            int a = _stack.top(); _stack.pop();
            int b = _stack.top(); _stack.pop();

            switch (c) {
                case '+': _stack.push(b + a); break;
                case '-': _stack.push(b - a); break;
                case '*': _stack.push(b * a); break;
                case '/':
                    if (a == 0)
						throw runtime_error("Error: Division by 0.");
                    _stack.push(b / a);
                    break;
            }
        }
    }

    if (_stack.size() != 1)
		throw runtime_error("Error: Invalid RPN expression.");


	if(_stack.size() == 1)
    	std::cout << "Result: " << _stack.top() << std::endl;

}

