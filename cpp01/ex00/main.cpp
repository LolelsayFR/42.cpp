/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:01:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/16 11:19:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*bernard;
	
	bernard = newZombie("Bernard");
	bernard->announce();
	delete bernard;
	randomChump("Alfredo");
}
