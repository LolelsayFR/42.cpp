/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 08:04:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/26 18:31:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	//Mandatory member atribute
	const std::string	_name;
	int					_grade;
public:
	//Constructors and destructors
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat(void);
	//Operator overload functions
	Bureaucrat& operator=(Bureaucrat &other);
	void operator++(void);
	void operator--(void);
	//Getter
	const std::string getName(void) const;
	int getGrade(void) const;
	//Exeptions class
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