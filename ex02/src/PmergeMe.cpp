#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe default constructor called!" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv){
	parseArguments(argc, argv);
	printDeque();
	std::cout << "== _VECT ==" << std::endl;
	printVector(_vect);
	makePairV();
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

void PmergeMe::parseArguments(int argc, char** argv){
	if (argc < 2)
		throw std::invalid_argument("No numbers provided");

	for (int i = 1; i < argc; ++i) {
		int num = isValidNumber(argv[i]); // peut lancer une exception
		_vect.push_back(num);
		_deque.push_back(num);
	}
}

int PmergeMe::isValidNumber(const std::string& s) const {
    if (s.empty())
        throw std::invalid_argument("Empty argument");

    for (size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            throw std::invalid_argument("Invalid character in argument");
    }

    std::stringstream ss(s);
    int n;
    ss >> n;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid number");
    }
    return n;
}

std::deque<int> PmergeMe::getDeque() const {return _deque;}
std::vector<int> PmergeMe::getVector() const {return _vect;}

void PmergeMe::printDeque() const{
	for(size_t i = 0; i < _deque.size(); ++i)
	{
		std::cout << C_PASTEL_PURPLE << _deque[i] << " " C_RESET << std::endl;
	}	
}

void PmergeMe::printVector(std::vector<int>& vect) const{
	for(size_t i = 0; i < vect.size(); ++i)
	{
		std::cout << C_QUARTZ << vect[i] << " " C_RESET << std::endl;
	}	
}

void PmergeMe::makePairV() const{
	std::vector<int> maxs, mins;
	size_t i = 0;
	while(i + 1 < _vect.size())
	{
		if(_vect[i] > _vect[i + 1]){
			maxs.push_back(_vect[i]);
			mins.push_back(_vect[i + 1]);
			std::cout << "MAXS.PB --> " << _vect[i] << std::endl;
			std::cout << "MINS.PB --> " << _vect[i + 1] << std::endl;
		}
		else{
			maxs.push_back(_vect[i + 1]);
			mins.push_back(_vect[i]);
			std::cout << "MAXS.PB --> " << _vect[i + 1] << std::endl;
			std::cout << "MINS.PB --> " << _vect[i] << std::endl;
		}
		i += 2;
	}
	if(i < _vect.size()){
		maxs.push_back(_vect[i]);
		std::cout << "MAXS.PB IF ODD and LAST --> " << _vect[i] << std::endl;
	}
	std::cout << "== MAXS ==" << std::endl;
	printVector(maxs);
	std::cout << "== MINS ==" << std::endl;
	printVector(mins);
}

// void PmergeMe::mergeVectSort(std::vector<int>& vect) const
// {
// 	std::vector<int> maxs, mins;

// }