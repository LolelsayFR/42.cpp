/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:53:34 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/19 11:38:27 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>
# define INV_SIZE 4

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inventory[INV_SIZE];
	bool		_notEmptySlot[INV_SIZE];
public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif // CHARACTER_HPP
