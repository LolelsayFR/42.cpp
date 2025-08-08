/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:01:13 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/08 08:20:10 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void mass(int nb) {
	if (nb % 2 == 1)
		nb++;

	const Animal* mass[nb];
	
	for (int i = 0; i < nb; i++) {
		std::cout << YEL "Hello animal id : " << i + 1 << RES << " " << std::endl;
		if (i < nb / 2)
			mass[i] = new Dog;
		else
			mass[i] = new Cat;
	}
	for (int i = 0; i < nb; i++) {
		std::cout << YEL "Byebye animal id : " << i + 1 << RES << " " << std::endl;
		delete mass[i];
	}
}

void basic(void) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete i;
	delete j;
}

void idea(void) {
	Cat cat;

	cat.addIdea("Miaou");
	cat.addIdea("MiaouMiaou");

	const Animal* newCat = new Cat(cat);

	((Cat*)newCat)->addIdea("MiaouMiaou but in animal const pointer");
    ((Cat*)newCat)->printIdeas();
	delete newCat;
}

int main(int ac, char **av) {
	std::cout << std::endl <<  BLU "Mass test :" << RES << " " << std::endl;
	if (ac != 2 || std::atoi(av[1]) <= 0)
		mass(100);
	else
		mass(std::atoi(av[1]));
	std::cout << std::endl << BLU "'Idea' test :" << RES << " " << std::endl;
	idea();
	std::cout << std::endl << BLU "Basic test :" << RES << " " << std::endl;
	basic();
	return (0);
}
