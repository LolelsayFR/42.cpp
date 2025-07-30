/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:35:35 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 05:52:10 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RED	"\e[48;2;75;0;0;1m "
# define GRN	"\e[48;2;0;75;0;1m "
# define BLU	"\e[48;2;0;0;75;1m "
# define RES	" \e[0m"

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	std::string	getType(void) const;
	virtual void	makeSound(void) const;
};

#endif // WRONGANIMAL_HPP