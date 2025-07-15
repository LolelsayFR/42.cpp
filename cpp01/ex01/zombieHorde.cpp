/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:02:03 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:45:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string Name )
{
	Zombie 	*newOne;

	newOne = new Zombie[N];
	for (int i = 0; i < N; i++)
		newOne[i].setName(Name);
	return (newOne);
}