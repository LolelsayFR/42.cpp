/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:13:56 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 20:50:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

class NotFoundException : public std::exception {
public :
	virtual const char* what(void) const throw() {
		return ("🛑 Value not found in container");
	};
};

template<typename T>
void easyfind(T& container, const int& i) {
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it != container.end()) {
		std::cout << "🤑 Value found for " << i << " !! Pos = " << std::distance(container.begin(), it) << std::endl;
		return;
	}
	throw NotFoundException();
}