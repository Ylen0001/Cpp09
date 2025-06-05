#include <iostream>
#include "../includes/MutantStack.hpp"
#include <list>

/* Version MutantStack */

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	return 0;
}

/* Version list */

// int main()
// {
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.back() << std::endl;

// 	mstack.pop_back();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
	
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
	
// 	std::list<int> s(mstack);
// 	return 0;
// }

/* TESTS SUPPLÉMENTAIRES */

// int main() {
//     MutantStack<int> mstack;

//     // On pousse des éléments
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << "Top: " << mstack.top() << std::endl; // 17

//     mstack.pop();

//     std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     // Test de l’itération
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     std::cout << "MutantStack contents:" << std::endl;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     return 0;
// }

/* 
top() affiche le dernier élément poussé (LIFO) → 17

Après pop(), 17 est retiré, il ne reste qu’un élément (5) → taille 1

Ensuite, les éléments sont ajoutés à la fin → la pile devient
[5, 3, 5, 737, 0]

L’itérateur begin() commence au bas de la pile (premier élément inséré) et end() à la fin

La boucle affiche donc tous les éléments dans l’ordre d’insertion, pas dans l’ordre d’extraction !
*/