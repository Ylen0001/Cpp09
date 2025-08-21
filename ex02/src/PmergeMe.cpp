#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe default constructor called!" << std::endl;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe destructor called!" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	// std::cout << "PmergeMe copy constructor called!" << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	// std::cout << "PmergeMe copy assignment operator called!" << std::endl;
	if (this != &other) {
		// Copie des attributs ici
	}
	return *this;
}