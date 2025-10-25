/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:05:38 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 13:41:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size), _data(new T[size]) {}	

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _data(new T[other._size]) {
	for (unsigned int i = 0; i < _size; ++i) {
		_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what(void) const throw() {
	return ("🛑 Array index out of bounds");
}
