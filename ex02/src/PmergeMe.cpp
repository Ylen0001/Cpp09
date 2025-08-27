#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv){
	parseArguments(argc, argv);
}


PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	// std::cout << "PmergeMe copy assignment operator called!" << std::endl;
	if (this != &other) {
		this->_deque = other._deque;
		this->_vect = other._vect;
		this->_maxs = other._maxs;
		this->_maxsD = other._maxsD;
		this->_mins = other._mins;
		this->_minsD = other._minsD;
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

std::deque<int>& PmergeMe::getDeque() {return _deque;}
std::deque<int>& PmergeMe::getMinsD() {return _minsD;}
std::deque<int>& PmergeMe::getMaxsD() {return _maxsD;}
std::vector<int>& PmergeMe::getVector() {return _vect;}
std::vector<int>& PmergeMe::getMaxsVect() {return _maxs;}
std::vector<int>& PmergeMe::getMinsVect() {return _mins;}

const std::deque<int>& PmergeMe::getDeque() const { return _deque; }
const std::deque<int>& PmergeMe::getMaxsD() const {return _maxsD;}
const std::deque<int>& PmergeMe::getMinsD() const {return _minsD;}
const std::vector<int>& PmergeMe::getVector() const { return _vect; }
const std::vector<int>& PmergeMe::getMaxsVect() const { return _maxs; }
const std::vector<int>& PmergeMe::getMinsVect() const { return _mins; }

/* Display complet */

// void PmergeMe::printDeque(std::deque<int>& deque) const{
// 	for(size_t i = 0; i < deque.size(); ++i)
// 	{
// 		std::cout << C_PASTEL_PURPLE << deque[i] << " " C_RESET;
// 	}	
// 	std::cout << std::endl;
// }

// void PmergeMe::printVector(std::vector<int>& vect) const{
// 	for(size_t i = 0; i < vect.size(); ++i)
// 	{
// 		std::cout << C_LAVENDER_PURPLE << vect[i] << " " C_RESET;
// 	}
// 	std::cout << std::endl;
// }

/* Display tronqué */

void PmergeMe::printVector(const std::vector<int>& vect) const
{
    size_t limit = 20;
    for(size_t i = 0; i < vect.size(); ++i)
    {
        if(i >= limit) {
            std::cout << "[...]" C_RESET;
            break;
        }
        std::cout << C_PASTEL_BLUE << vect[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int>& deq) const
{
    size_t limit = 20;
    for(size_t i = 0; i < deq.size(); ++i)
    {
        if(i >= limit) {
            std::cout << "[...]" C_RESET;
            break;
        }
        std::cout << C_PASTEL_PURPLE << deq[i] << " ";
    }
    std::cout << std::endl;
}



void PmergeMe::run()
{
    // ----------------- VECTOR -----------------
    std::clock_t start_vect = std::clock();

    makePairV();
	mergeSortVOptim(_maxs);
    insertBInMainChainV(_maxs, _mins);
	
    std::clock_t end_vect = std::clock();
    double time_vect = 1000000.0 * (end_vect - start_vect) / CLOCKS_PER_SEC; // microsecondes

	std::cout << C_DUSTY_RED"== _VECT ==" C_RESET<< std::endl;
    std::cout << "Before: ";
    printVector(_vect); // version adaptée pour [...] si grande
    std::cout << "After: ";
    printVector(_maxs);
    std::cout << "Time to process a range of " << _vect.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << C_MINT << time_vect
              << " us" << C_RESET << std::endl;

    // ----------------- DEQUE -----------------
    std::clock_t start_deque = std::clock();

    makePairD();
	mergeSortDOptim(_maxsD);
    insertBInMainChainD(_maxsD, _minsD);

    std::clock_t end_deque = std::clock();
    double time_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

	std::cout << C_ROSE_RED"=== DEQUE ===" C_RESET << std::endl;
    std::cout << "Before: ";
    printDeque(_deque); // version adaptée pour [...] si grande
    std::cout << "After: ";
    printDeque(_maxsD);
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : "
              << std::fixed << std::setprecision(5) << C_MINT << time_deque
              << " us" << C_RESET << std::endl;
}


std::vector<int> PmergeMe::generateJacobStahl(size_t n)
{
	std::vector<int> J;
	if(n == 0) return J;
	J.push_back(0);
	if(n == 1) return J;
	J.push_back(1);

	for(size_t i = 2; (size_t)J.back() < n; ++i)
	{
		size_t next = J[i-1] + 2 * J[i - 2];
		if(next >= n) break;
		J.push_back(next);
	}
	return J;
}

void PmergeMe::insertBInMainChainV(std::vector<int>& mainChain, const std::vector<int>& mins)
{
	// Étape 1 : trier les mins
	std::vector<int> sortedMins = mins;
	mergeSortVOptim(sortedMins);

	// Étape 2 : générer la suite de Jacobsthal
	std::vector<int> jac = generateJacobStahl(sortedMins.size());

	// Étape 3 : créer un vecteur temporaire pour le résultat final
	std::vector<int> result;
	result.reserve(mainChain.size() + sortedMins.size());

	std::vector<bool> inserted(sortedMins.size(), false);

	// Insérer d'abord les éléments de sortedMins selon Jacobsthal
	for (size_t k = 0; k < jac.size(); ++k)
	{
		int idxB = jac[k];
		if (idxB >= (int)sortedMins.size() || inserted[idxB])
			continue;

		int value = sortedMins[idxB];

		// Recherche binaire dans result pour trouver la position d'insertion
		int low = 0, high = result.size();
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (result[mid] < value)
			    low = mid + 1;
			else
				high = mid;
        }
		result.insert(result.begin() + low, value);
		inserted[idxB] = true;
    }

	// Étape 4 : fusionner _maxs déjà trié dans result
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		// Recherche binaire pour insérer mainChain[i] dans result
		int value = mainChain[i];
		int low = 0, high = result.size();
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (result[mid] < value)
				low = mid + 1;
			else
				high = mid;
		}
		result.insert(result.begin() + low, value);
    }

    // Étape 5 : insérer tous les éléments restants de sortedMins
    for (size_t i = 0; i < sortedMins.size(); ++i)
    {
        if (inserted[i])
            continue;

        int value = sortedMins[i];
        int low = 0, high = result.size();
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (result[mid] < value)
                low = mid + 1;
            else
                high = mid;
        }
        result.insert(result.begin() + low, value);
    }

    // Étape 6 : remplacer mainChain par le résultat final trié
    mainChain = result;
}



void PmergeMe::insertSortV()
{
	for(size_t k = 0; k < _mins.size(); ++k)
	{
		int m = _mins[k]; int low = 0; int high = _maxs.size();

		while(low < high){
			int mid = (low + high) / 2;
			if(_maxs[mid] < m)
				low = mid + 1;
			else
				high = mid;
		}
		_maxs.insert(_maxs.begin() + low, m);
	}
}

void PmergeMe::makePairV(){
	size_t i = 0;
	while(i + 1 < _vect.size())
	{
		if(_vect[i] > _vect[i + 1]){
			getMaxsVect().push_back(_vect[i]);
			getMinsVect().push_back(_vect[i + 1]);
		}
		else{
			getMaxsVect().push_back(_vect[i + 1]);
			getMinsVect().push_back(_vect[i]);
		}
		i += 2;
	}
	if(i < _vect.size()){
		getMaxsVect().push_back(_vect[i]);
	}
}


void PmergeMe::mergeSortVOptim(std::vector<int>& vect) {
    std::vector<int> temp(vect.size()); // vecteur temporaire unique
    mergeSortVRec(vect, temp, 0, vect.size());
}

void PmergeMe::mergeSortVRec(std::vector<int>& vect, std::vector<int>& temp, int start, int end) {
    if (end - start <= 1) return;
    int mid = start + (end - start) / 2;

    mergeSortVRec(vect, temp, start, mid);
    mergeSortVRec(vect, temp, mid, end);

    int i = start, j = mid, k = start;
    while (i < mid && j < end) {
        if (vect[i] < vect[j]) temp[k++] = vect[i++];
        else temp[k++] = vect[j++];
    }
    while (i < mid) temp[k++] = vect[i++];
    while (j < end) temp[k++] = vect[j++];

    for (int l = start; l < end; ++l)
        vect[l] = temp[l];
}




// Recursive functions -> Dividing Maxs into two sub vects.
// void PmergeMe::mergeSortV(std::vector<int>& vect) const
// {
// 	if(vect.size() <= 1) return;
// 	size_t mid = vect.size() / 2;
// 	std::vector<int> left, right;
// 	for (size_t i = 0; i < vect.size(); ++i) {
// 		if (i < mid)
// 			left.push_back(vect[i]);
// 		else
// 			right.push_back(vect[i]);
// 	}
// 	// Recursive call to function
// 	mergeSortV(left);
// 	mergeSortV(right);
// 	size_t i, j;
// 	i = 0; j = 0;
// 	vect.clear();
// 	// Merge sorting 'til left or right's size's reached.
// 	while(i < left.size() && j < right.size())
// 	{
// 		if(left[i] < right[j])
// 		{
// 			vect.push_back(left[i]);
// 			i++;
// 		}
// 		else {
// 			vect.push_back(right[j]);
// 			j++;
// 		}
// 	}
// 	// If odd vector --> We're filling what's left in vect depending on which one
// 	// between l/r has still one value left.
// 	while (i < left.size()) {
// 	vect.push_back(left[i]);
// 	i++;
// 	}

// 	while (j < right.size()) {
// 	vect.push_back(right[j]);
// 	j++;
// 	}
// }


void PmergeMe::makePairD(){
	size_t i = 0;
	while(i + 1 < _deque.size())
	{
		if(_deque[i] > _deque[i + 1]){
			getMaxsD().push_back(_deque[i]);
			getMinsD().push_back(_deque[i + 1]);
		}
		else{
			getMaxsD().push_back(_deque[i + 1]);
			getMinsD().push_back(_deque[i]);
		}
		i += 2;
	}
	if(i < _deque.size()){
		getMaxsD().push_back(_deque[i]);
	}
}

void PmergeMe::mergeSortDOptim(std::deque<int>& deq) {
	std::vector<int> temp(deq.begin(), deq.end()); // copie en vector
	mergeSortVOptim(temp); // on réutilise la version optimisée vector
	deq.assign(temp.begin(), temp.end()); // recopie dans le deque
}

void PmergeMe::mergeSortDRec(std::deque<int>& deq, int start, int end) {
    if (end - start <= 1) return;
    int mid = start + (end - start) / 2;

    mergeSortDRec(deq, start, mid);
    mergeSortDRec(deq, mid, end);

    std::deque<int> merged;
    int i = start, j = mid;

    while (i < mid && j < end) {
        if (deq[i] < deq[j]) merged.push_back(deq[i++]);
        else merged.push_back(deq[j++]);
    }
    while (i < mid) merged.push_back(deq[i++]);
    while (j < end) merged.push_back(deq[j++]);

    // recopie dans le deque original
    for (int k = 0; k < (int)merged.size(); ++k)
        deq[start + k] = merged[k];
}

void PmergeMe::insertBInMainChainD(std::deque<int>& mainChain, const std::deque<int>& mins) {
    std::vector<int> jac = generateJacobStahl(mins.size());
    std::vector<bool> inserted(mins.size(), false); // Marque les éléments déjà insérés

    // 1️⃣ Insertion selon Jacobstahl
    for(size_t k = 0; k < jac.size(); ++k) {
        size_t idxB = jac[k];
        if(idxB >= mins.size() || inserted[idxB]) continue;

        int value = mins[idxB];

        // Binary search insertion
        size_t low = 0, high = mainChain.size();
        while(low < high) {
            size_t mid = (low + high) / 2;
            if(mainChain[mid] < value)
                low = mid + 1;
            else
                high = mid;
        }
        mainChain.insert(mainChain.begin() + low, value);
        inserted[idxB] = true;
    }

    // 2️⃣ Insertion des éléments restants
    for(size_t i = 0; i < mins.size(); ++i) {
        if(inserted[i]) continue;

        int value = mins[i];
        size_t low = 0, high = mainChain.size();
        while(low < high) {
            size_t mid = (low + high) / 2;
            if(mainChain[mid] < value)
                low = mid + 1;
            else
                high = mid;
        }
        mainChain.insert(mainChain.begin() + low, value);
        inserted[i] = true;
    }
}


void PmergeMe::insertSortD()
{
	for(size_t k = 0; k < _minsD.size(); ++k)
	{
		int m = _minsD[k]; int low = 0; int high = _maxsD.size();

		while(low < high){
			int mid = (low + high) / 2;
			if(_maxsD[mid] < m)
				low = mid + 1;
			else
				high = mid;
		}
		_maxsD.insert(_maxsD.begin() + low, m);
	}
}