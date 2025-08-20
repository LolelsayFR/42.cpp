/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:37:50 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 16:16:55 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

# define COL	"\e[1;38;5;0;107m "
# define RES	" \e[0m"

int	subject() {
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

void	deep_char_test() {
	Character	base("Bernard");
	AMateria*	matIce = new Ice();

	base.equip(matIce);

	ICharacter*	copy = new Character(base);

	base.unequip(0);
	delete matIce;
	std::cout << "Try to use copy of deleted materia" << std::endl;
	copy->use(0, base);
	delete copy;
}

void	deep_mat_source_test() {
	AMateria*		clone;
	MateriaSource	base;

	base.learnMateria(new Cure);
	IMateriaSource* copy = new MateriaSource(base);
	base.learnMateria(new Ice);
	clone = copy->createMateria("ice");
	std::cout << "Try to create Ice with old copy : Materia adresse " << clone << std::endl;
	delete clone;
	delete copy;
}

void	not_learn_test() {
	MateriaSource	src;
	Character		chara("Jaque");

	src.learnMateria(new Ice);

	std::cout << "Try to equip unlearned materia from source and use first materia" << std::endl;
	chara.equip(src.createMateria("zazaaa"));
	chara.equip(src.createMateria("cure"));
	chara.use(0, chara);
}

int	main() {
	std::cout << COL"Subject Main" << RES << std::endl;
	subject();
	std::cout << COL"My Main : Deep copy test Character" << RES << std::endl;
	deep_char_test();
	std::cout << COL"My Main : Deep copy test MateriaSource" << RES << std::endl;
	deep_mat_source_test();
	std::cout << COL"My Main : Equip not learned materia" << RES << std::endl;
	not_learn_test();
	return 0;
}
