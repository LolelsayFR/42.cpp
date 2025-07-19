/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:02:03 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 16:38:50 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string Name )
{
	Zombie 	*NewOne;

	NewOne = new Zombie[N];
	for (int i = 0; i < N; i++)
		NewOne[i].setName(Name);
	return (NewOne);
}