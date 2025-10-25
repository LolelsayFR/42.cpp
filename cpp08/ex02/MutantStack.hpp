/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:34:08 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 16:49:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iterator>

//Stack is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
//By default, the underlying container to use is std::deque.

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	~MutantStack() {}
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	//container_type is the type of the underlying container (e.g., std::deque)

	iterator begin() {
		return this->c.begin(); //This.c is the underlying container of the stack
	}
	iterator end() {
		return this->c.end(); //This.c is the underlying container of the stack
	}

};	