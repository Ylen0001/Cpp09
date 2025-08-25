#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime> 
#include <deque>
#include <vector>
#include "colors.hpp"
#include <string>
#include <stdexcept>
#include <sstream>
#include <cctype>

class PmergeMe {
	private:
		std::deque<int> _deque;
		std::vector<int> _vect;
		std::vector<int> _maxs;
		std::vector<int> _mins;
		void parseArguments(int argc, char** argv);
		int isValidNumber(const std::string& s) const;

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		std::deque<int> getDeque() const;
		std::vector<int> getVector() const;
		void printDeque() const;
		void printVector(std::vector<int>& vect) const;
		void makePairV() const;
		void mergeVectSort(std::vector<int>& vect) const;
};

#endif