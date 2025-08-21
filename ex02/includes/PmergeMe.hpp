#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime> 
#include <deque>
#include <vector>

class PmergeMe {
	private:
		

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
};

#endif