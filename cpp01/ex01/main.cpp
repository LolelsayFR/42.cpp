/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:01:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 16:39:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*Joe;
	int		N;

	N = 10;
	Joe = zombieHorde(N, "Joe la fripouille");
	for (int i = 0; i < N; i++)
		Joe[i].announce();
	delete[] Joe;
}
