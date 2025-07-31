/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:50:37 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 09:54:44 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

class Cure
{
private:

public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();
};

#endif // CURE_HPP