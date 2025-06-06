/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:40:28 by ylenoel           #+#    #+#             */
/*   Updated: 2025/06/06 13:12:00 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange(const std::string& dataBaseFile)
{
	loadDataFromFile(dataBaseFile);
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
	processInputFromFile(filename);
}

void BitcoinExchange::loadDataFromFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error : couldn't open file " << filename << std::endl;
		return;
	}
	
	std::string line;
	while(std::getline(file, line))
	{
		if(!line.empty())
			loadDataLine(line);
	}
}


void BitcoinExchange::processInputFromFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty()) {
			processLine(line);
		}
	}
}

void BitcoinExchange::loadDataLine(const std::string& line)
{
	if(line == "date, exchange_rate")
		return;
	
	std::istringstream ss(line);
	std::string date, rateStr;

	if(!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
	{
		std::cerr << "Error: bad data line -> " << line << std::endl;
		return;
	}
	
	trim(date);
	trim(rateStr);

	float rate = std::atof(rateStr.c_str());
	_rates[date] = rate;
}

void BitcoinExchange::processLine(const std::string& line) const
{
	if(line == "date | value")
		return;
	std::istringstream ss(line);
	std::string date, valueStr;

	if(!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
	{
		std::cerr << "Error: bad input -> " << line << std::endl;
		return;
	}

	trim(date);
	trim(valueStr);

	if(!isValidDate(date))
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		return;
	}

	float value = std::atof(valueStr.c_str());

	if(value < 0)
	{
		std::cerr << "Error : not a positive number." << std::endl;
		return;
	}
	
	if(value > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return;
	}
	
	float rate = getRateForDate(date);
	std::cout << date << " -> " << value << " = " << std::fixed << std::setprecision(2) << value * rate << std::endl;
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date) {
		return it->second;
	}
	if (it == _rates.begin()) {
		return 0.0f; // Aucun taux avant cette date
	}
	--it;
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if(date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if(year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	return true;
}

void BitcoinExchange::trim(std::string& str) const
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if(start == std::string::npos) // Si start n'a trouvé que des espaces dans la string.
		str = "";
	else
		str = str.substr(start, end - start + 1);
}