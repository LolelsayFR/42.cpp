/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:35:35 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/08 09:08:23 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RED	"\e[48;2;75;0;0;1m "
# define GRN	"\e[48;2;0;75;0;1m "
# define BLU	"\e[48;2;0;0;75;1m "
# define YEL	"\e[48;2;100;100;0;1m "
# define RES	" \e[0m"

class Animal
{
protected:
	Animal();
	std::string	type;
public:
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	std::string	getType(void) const;
	virtual void	makeSound(void) const = 0;
};

#endif // ANIMAL_HPP
