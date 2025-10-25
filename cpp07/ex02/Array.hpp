/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:02 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 13:17:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>


template <typename T> class Array {
private:
	unsigned int _size;
	T* _data;
public:
	Array();
	Array(unsigned int size);
	Array(const Array& other);
	~Array();
	T& operator[](unsigned int index);
	unsigned int size() const;
	class OutOfBoundsException : public std::exception {
		public :
		virtual const char* what(void) const throw();
	};
};