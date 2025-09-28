/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:39:45 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 14:11:12 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
public:	
	//Constructors and destructor
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(PresidentialPardonForm &other);
	~PresidentialPardonForm(void);
	//All overload
	PresidentialPardonForm& operator=(PresidentialPardonForm &other);
	//Other utils
	void doSomething(void) const;
};	

#endif // PRESIDENTIALPARDONFORM_HPP