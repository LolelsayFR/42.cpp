/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:39:45 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 11:33:07 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	//Mandatory private atribute
	const std::string	_name;
	const int			_gradeToExecute;
	const int			_gradeToSign;
	bool				_isSigned;
public:
	//Constructors and destructor
	Form(void);
	Form(const std::string name, const int gts, const int gte);
	Form(Form &other);
	~Form(void);
	//All overload
	Form& operator=(Form &other);
	//All mandatory other member functions
	void beSigned(const Bureaucrat& bureaucrat);
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getIsSigned(void) const;
	//All exeptions
	class GradeTooLowException : public std::exception {
	public :
		virtual const char*	what(void) const throw();
	};
	class GradeTooHighException : public std::exception {
	public :
		virtual const char*	what(void) const throw();
	};
	
};

//Ostream insertion operator
std::ostream& operator<<(std::ostream& o, const Form& form);
	
#endif // FORM_HPP