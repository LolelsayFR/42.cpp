/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:12:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/03/25 18:04:36 by emaillet         ###   ########.fr       */
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
		std::string	name;
		std::string	surname;
		std::string	family_name;
		std::string	dark_secret;
		std::string	phone_number;
	public:
		Contact(void);
		~Contact(void);
		std::string data_ten_limit(void);
		void print(std::string i);
		void set(std::string name, std::string family_name, std::string surname,
				 std::string dark_secret, std::string phone_number);
};

# endif
