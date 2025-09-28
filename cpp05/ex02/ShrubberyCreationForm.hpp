/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:39:45 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 12:34:57 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
	public:	
	//Constructors and destructor
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);
	//All overload
	ShrubberyCreationForm& operator=(ShrubberyCreationForm &other);
	//Other utils
	void doSomething(void) const;
};	

#endif // SHRUBBERYCREATIONFORM_HPP