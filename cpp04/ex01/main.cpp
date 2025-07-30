/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:01:13 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 07:00:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void mass(void) {
	const Animal* mass[100];	

	for (int i = 0; i <= 100; i++) {
		std::cout << YEL "Hello animal id : " << i << RES << " " << std::endl;
		if (i < 50)
			mass[i] = new Dog;
		else
			mass[i] = new Cat;
	}
	for (int i = 0; i <= 100; i++) {
		std::cout << YEL "Byebye animal id : " << i << RES << " " << std::endl;
		delete mass[i];
	}
}

void basic(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

int main() {
	std::cout << std::endl <<  BLU "Mass test :" << RES << " " << std::endl;
	mass();
	std::cout << std::endl << BLU "Basic test :" << RES << " " << std::endl;
	basic();
	return (0);
}