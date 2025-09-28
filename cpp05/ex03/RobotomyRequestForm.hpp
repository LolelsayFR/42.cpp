/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:39:45 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 14:11:08 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:	
	//Constructors and destructor
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(RobotomyRequestForm &other);
	~RobotomyRequestForm(void);
	//All overload
	RobotomyRequestForm& operator=(RobotomyRequestForm &other);
	//Other utils
	void doSomething(void) const;
};	

#endif // ROBOTOMYREQUESTFORM_HPP