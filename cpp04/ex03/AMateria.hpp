/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:38:47 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 14:45:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
private:
	AMateria();
protected:
	bool		_onChar;
	std::string _type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	bool const & isOnCharacter() const;
	void setOnCharacter();
	void unsetOnCharacter();
};

#endif // AMATERIA_HPP
