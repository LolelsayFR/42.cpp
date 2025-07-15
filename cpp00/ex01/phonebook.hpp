/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:01:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:54:07 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "contact.hpp"

# define PF_PHBO "\e[48;2;70;70;70;1m PhoneBook \e[0m : "
# define PF_ADD "\e[48;2;0;70;0;1m Add \e[0m"
# define PF_SEARCH "\e[48;2;0;0;70;1m Search \e[0m"
# define PF_EXIT "\e[48;2;70;0;0;1m Exit \e[0m"
# define P "\e[48;2;70;0;70;1m"
# define R "\e[0m"

bool	IsOnlySpacer(std::string);

class Phonebook {
	private:
		Contact	contact[8];
		int		count;
	public:
		bool	isrunning;
		Phonebook(void);
		~Phonebook(void);
		void Print(void);
		void AddLoop(void);
		void SearchLoop(void);
};

# endif
