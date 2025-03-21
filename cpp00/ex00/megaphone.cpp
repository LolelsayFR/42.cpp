/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:12:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/03/20 05:29:59 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>

int	main(int argc, char *argv[])
{
	std::string	s;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		std::transform(s.begin(), s.end(), s.begin(), toupper);
		std::cout << s;
	}
	std::cout << std::endl;
	return (1);
}
