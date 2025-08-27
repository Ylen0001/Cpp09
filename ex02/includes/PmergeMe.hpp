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
#include <iomanip>

// #define MAX_DISPLAY 10

class PmergeMe {
	private:
		std::deque<int> _deque;
		std::deque<int> _maxsD;
		std::deque<int> _minsD;
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
		void run();
		std::vector<int> generateJacobStahl(size_t n);
		
		/* Vector version */
		
		std::vector<int>& getVector();
		std::vector<int>& getMaxsVect();
		std::vector<int>& getMinsVect();
		const std::vector<int>& getVector() const;
		const std::vector<int>& getMaxsVect() const;
		const std::vector<int>& getMinsVect() const;
		
		// void printVector(std::vector<int>& vect) const;
		void printVector(const std::vector<int>& vect) const;
		void makePairV();
		void mergeSortV(std::vector<int>& vect) const;
		void insertBInMainChainV(std::vector<int>& mainChain, const std::vector<int>& mins);
		void insertSortV();
		
		void mergeSortVRec(std::vector<int>& vect, std::vector<int>& temp, int start, int end);
		void mergeSortVOptim(std::vector<int>& vect);
		
		
		/* Deque version */
		
		std::deque<int>& getDeque();
		std::deque<int>& getMaxsD();
		std::deque<int>& getMinsD();
		const std::deque<int>& getDeque() const;
		const std::deque<int>& getMaxsD() const;
		const std::deque<int>& getMinsD() const;
		
		// void printDeque(std::deque<int>& deque) const;
		void printDeque(const std::deque<int>& deq) const;
		void makePairD();
		void mergeSortD(std::deque<int>& deque) const;
		void insertBInMainChainD(std::deque<int>& mainChain, const std::deque<int>& mins);
		void insertSortD();

		void mergeSortDOptim(std::deque<int>& deq);
		void mergeSortDRec(std::deque<int>& deq, int start, int end);

	};

#endif