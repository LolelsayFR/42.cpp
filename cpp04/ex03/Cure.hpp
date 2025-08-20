/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:50:37 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/19 11:40:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria 
{
private:

public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();
	AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // CURE_HPP
