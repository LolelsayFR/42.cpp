/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 06:17:24 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/08 07:07:59 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define RED	"\e[48;2;75;0;0;1m "
# define GRN	"\e[48;2;0;75;0;1m "
# define BLU	"\e[48;2;0;0;75;1m "
# define YEL	"\e[48;2;100;100;0;1m "
# define RES	" \e[0m"

# include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	void	addIdea(std::string idea);
	void	printIdeas(void);
	~Brain();
};

#endif // BRAIN_HPP
