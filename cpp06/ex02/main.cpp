/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:15:50 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 11:26:42 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void identify(Base* base) {
	if (dynamic_cast<A*>(base)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(base)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(base)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& base) {
	try {
		dynamic_cast<A&>(base);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try {
		dynamic_cast<B&>(base);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try {
		dynamic_cast<C&>(base);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
}

Base* generate(void) {
	static int i = 0;
	srand(time(NULL) + i++);
	int random = rand() % 3;
	switch (random) {
		case 0:
			std::cout << "A generated : " << std::endl;
			return (new A());
		case 1:
			std::cout << "B generated : " << std::endl;
			return (new B());
		case 2:
			std::cout << "C generated : " << std::endl;
			return (new C());
	}
	return (NULL);
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		std::cout << std::endl << "Test number " << i + 1 << ":" << std::endl;
		Base* rand = generate();
		std::cout << "Identify pointer " << " : ";
		identify(rand);
		std::cout << "Identify reference " << " : ";
		identify(*rand);
		delete rand;
	}
	return (0);
}