/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:04:03 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:45:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string Name;
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string Name);
};

Zombie* newZombie( std::string Name );
void randomChump( std::string Name );