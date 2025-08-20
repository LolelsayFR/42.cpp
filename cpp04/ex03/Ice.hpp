/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:49:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/18 09:05:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();
	AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // ICE_HPP
