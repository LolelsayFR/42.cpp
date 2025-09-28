/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 08:04:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/28 14:22:27 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	//Mandatory member atribute
	const std::string	_name;
	int					_grade;
public:
	//Constructors and destructor
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat(void);
	//Operator overload functions
	Bureaucrat& operator=(Bureaucrat &other);
	void operator++(void);
	void operator--(void);
	//Other member functions
	const std::string getName(void) const;
	int getGrade(void) const;
	void signForm(AForm& form);
	void executeForm(AForm const& form);
	//exceptions class
	class GradeTooHighException : public std::exception {
	public :
		virtual const char* what(void) const throw();		
	};
	class GradeTooLowException : public std::exception {
	public :
		virtual const char* what(void) const throw();
	};
};

//Other operator overload
std::ostream& operator<<(std::ostream& o, Bureaucrat& other);

#endif