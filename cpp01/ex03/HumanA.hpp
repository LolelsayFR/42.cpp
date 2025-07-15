/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:45:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string Name;
		Weapon	*weapon;
	public:
		HumanA();
		HumanA(std::string Name, Weapon &weapon);
		~HumanA();
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

#endif // HUMANA_HPP