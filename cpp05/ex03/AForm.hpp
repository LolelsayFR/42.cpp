/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:39:45 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 11:59:43 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	//Mandatory private atribute
	const std::string	_name;
	const int			_gradeToExecute;
	const int			_gradeToSign;
	bool				_isSigned;
public:
	//Constructors and destructor
	AForm(void);
	AForm(const std::string name, const int gts, const int gte);
	AForm(AForm &other);
	virtual ~AForm(void);
	//All overload
	AForm& operator=(AForm &other);
	//All mandatory other member functions
	virtual void beSigned(const Bureaucrat& bureaucrat);
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getIsSigned(void) const;
	void setIsSigned(void);
	void execute(Bureaucrat const& executor) const;
	//All exceptions
	class GradeTooLowException : public std::exception {
	public :
		virtual const char*	what(void) const throw();
	};
	class GradeTooHighException : public std::exception {
	public :
		virtual const char*	what(void) const throw();
	};
	class CantExecException : public std::exception {
	public :
		virtual const char*	what() const throw();
	};
	//My utils functions
	virtual void doSomething(void) const = 0;
};

//Ostream insertion operator
std::ostream& operator<<(std::ostream& o, const AForm& AForm);
	
#endif // AForm_HPP