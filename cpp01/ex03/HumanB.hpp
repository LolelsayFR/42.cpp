/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/10 17:05:31 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon	*weapon;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		void	setName(std::string name)
		{
			this->name = name;
		}
		void	setWeapon(Weapon &weapon)
		{
			this->weapon = &weapon;
		}
};

#endif // HUMANB_HPP