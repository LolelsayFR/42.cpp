/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:12:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 10:00:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <cstring>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <cstdlib>

class Contact {
	private:
		std::string	Name;
		std::string	NickName;
		std::string	LastName;
		std::string	DarkestSecret;
		std::string	PhoneNumber;
	public:
		Contact(void);
		~Contact(void);
		std::string PrintData(int arg);
		void print(std::string i);
		void SetData(std::string Name, std::string NickName, std::string LastName,
				 std::string DarkestSecret, std::string PhoneNumber);
};

# endif
