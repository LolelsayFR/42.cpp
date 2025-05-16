/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:01:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/16 12:04:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*joe;
	int		N;

	N = 10;
	joe = zombieHorde(N, "Joe la fripouille");
	for (int i = 0; i < N; i++)
		joe[i].announce();
	delete[] joe;

}
