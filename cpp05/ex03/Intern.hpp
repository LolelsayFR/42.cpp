/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:34:22 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 16:50:38 by lolelsay         ###   ########.fr       */
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
	//All operator overload
	Intern& operator=(Intern &other);
	AForm* makeForm(std::string name, std::string target) const;
};

#endif // INTERN_HPP