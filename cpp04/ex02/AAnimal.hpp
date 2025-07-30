/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:35:35 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 07:48:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define RED	"\e[48;2;75;0;0;1m "
# define GRN	"\e[48;2;0;75;0;1m "
# define BLU	"\e[48;2;0;0;75;1m "
# define YEL	"\e[48;2;100;100;0;1m "
# define RES	" \e[0m"

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();
	std::string	getType(void) const;
	virtual void	makeSound(void) const = 0;
};

#endif // AANIMAL_HPP