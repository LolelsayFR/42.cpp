/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:53:34 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 10:00:36 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

class Character
{
private:

public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
};

#endif // CHARACTER_HPP