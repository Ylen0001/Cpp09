/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:59:10 by yoann             #+#    #+#             */
/*   Updated: 2025/06/05 15:59:44 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

std::map<std::string, double> loadData(const std::string& filename)
{
	std::map<std::string, double> priceData;
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return priceData; 
	}

	std::string line;
	std::getline(file, line); // Ignore le header
	
	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, priceStr;

		if(!std::getline(ss, date, ',') || !std::getline(ss, priceStr))
		{
			std::cerr << "Warning: bad line format -> " << line << std::endl;
			continue;
		}

		double price;
		std::stringstream ssPrice(priceStr);
		ssPrice >> price;
		if(ssPrice.fail())
		{
			std::cerr << "Warning: invalid price value -> " << priceStr << std::endl;
			continue;
		}
		priceData[date] = price;
	}
	file.close();
	return priceData;
}


int main() 
{
	std::map<std::string, double> btcPrices = loadData("data.csv");

	for (std::map<std::string, double>::const_iterator it = btcPrices.begin(); it != btcPrices.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	return 0;
}
