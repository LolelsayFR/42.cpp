/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:34:22 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/29 09:52:27 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

class Intern {
public:	
	//All constructors and destructor
	Intern(void);
	Intern(Intern &other);
	~Intern(void);
	//Copy operator overload
	Intern& operator=(Intern &other);
	//Mandatory member function
	AForm* makeForm(std::string name, std::string target) const;
	//All exceptions class
	class CantMakeFormException : public std::exception {
	public :
		virtual const char* what(void) const throw();
	};
};

#endif // INTERN_HPP