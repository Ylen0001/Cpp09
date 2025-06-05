/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:55:01 by yoann             #+#    #+#             */
/*   Updated: 2025/06/02 16:01:47 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <string>


// int main() {
// 	try {
// 		Span sp(10000);
// 		std::vector<int> numbers(10000);
// 		for (int i = 0; i < 10000; ++i)
// 			numbers[i] = i;

// 		sp.addRange(numbers.begin(), numbers.end());

// 		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// 	}
// 	catch (const std::exception& e) {
// 		std::cerr << "Exception caught: " << e.what() << std::endl;
// 	}

// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
 
	return (0);
}