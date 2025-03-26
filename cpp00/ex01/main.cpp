/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:16:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/03/25 18:27:25 by emaillet         ###   ########.fr       */
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
		if (handler == "EXIT" || handler == "exit" || handler == "Exit")
			break ;
		else if (handler == "ADD" || handler == "add" || handler == "Add")
			book.add_loop();
		else if (handler == "SEARCH" || handler == "search" || handler == "Search")
			book.search_loop();
		if (!std::getline (std::cin, handler))
			break ;
	}
	std::cout << PF_EXIT << std::endl;
}

bool	is_only_spacer(std::string str)
{
    const char	*c_str = str.c_str();

    for (int i = 0; c_str[i] != '\0'; i++)
    {
        if (c_str[i] != ' ' && c_str[i] != '\t' && c_str[i] != '\n'
        && c_str[i] != '\v' && c_str[i] != '\f' && c_str[i] != '\r')
            return (false);
    }
    return (true);
}
