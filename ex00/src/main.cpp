/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:59:10 by yoann             #+#    #+#             */
/*   Updated: 2025/06/06 13:14:13 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc input.txt" << std::endl;
		return 1;
	}
	
	BitcoinExchange btc("data.csv");
	btc.processInputFile(argv[1]);

	return 0;
}
