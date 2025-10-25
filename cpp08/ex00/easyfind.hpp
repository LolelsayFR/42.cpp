/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:13:56 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 14:49:27 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class NotFoundException : public std::exception {
public :
	virtual const char* what(void) const throw() {
		return ("🛑 Value not found in container");
	};
};

template<typename T>
void easyfind(T& container, const int& i) {
	int pos = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); ++pos, ++it) {
		if (*it == i) {
			std::cout << "🤑 Value found for "<< i <<" !! Pos = " << pos << std::endl;
			return ;
		}
	}
	throw NotFoundException();
}