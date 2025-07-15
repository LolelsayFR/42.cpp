/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:16:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 10:15:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	Phonebook book;
	std::string	handler;
	book.isrunning = true;
	while (book.isrunning)
	{
		handler = "";
		std::cout << PF_PHBO;
		if (!std::getline (std::cin, handler))
			break ;
		if (handler == "EXIT")
			break ;
		else if (handler == "ADD")
			book.AddLoop();
		else if (handler == "SEARCH")
			book.SearchLoop();
	}
	std::cout << PF_EXIT << std::endl;
}

bool	IsOnlySpacer(std::string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
            return (false);
    }
    return (true);
}
