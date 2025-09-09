/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:18:07 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/12 05:31:17 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Usage: " << av[0] << " <log_level>" << std::endl
			<< "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl, 1);
	Harl harl;
	harl.complain(av[1]);
	return (0);
}
