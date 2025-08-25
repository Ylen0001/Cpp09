/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:55:01 by yoann             #+#    #+#             */
/*   Updated: 2025/08/25 11:42:03 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rpn.hpp"

int main(int argc, char** argv) {
    try{
		if (argc != 2) {
			std::cerr << "Usage: ./RPN \"<rpn expression>\"" << std::endl;
			return EXIT_FAILURE;
		}

		std::string expr(argv[1]);

		// Vérifier qu’il y a au moins un espace
		if (expr.find(' ') == std::string::npos) {
			std::cerr << "Error: Expression must have spaces between tokens." << std::endl;
			return EXIT_FAILURE;
		}

		RPN test(expr);
		test.process();
	} catch (const std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

    return (0);
}