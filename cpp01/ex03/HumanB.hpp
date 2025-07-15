/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:45:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string Name;
		Weapon	*weapon;
	public:
		HumanB();
		HumanB(std::string Name);
		~HumanB();
		void	attack(void);
		void	setName(std::string Name)
		{
			this->Name = Name;
		}
		void	setWeapon(Weapon &weapon)
		{
			this->weapon = &weapon;
		}
};

#endif // HUMANB_HPP