/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:37:20 by ylenoel           #+#    #+#             */
/*   Updated: 2025/08/18 17:49:34 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& databaseFile);
		void processInputFile(const std::string& filename) const;

	private:
		std::map<std::string, float> _rates;
		
		void loadDataFromFile(const std::string& filename);
		void processInputFromFile(const std::string& filename) const;
		
		void loadDataLine(const std::string& line);
		void processLine(const std::string& line) const;

		float getRateForDate(const std::string& date) const;
		bool isValidDate(const std::string& date) const;
		void trim(std::string& str) const;
		bool isLeapYear(int year) const;
		
};

#endif