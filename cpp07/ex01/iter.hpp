/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:17 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/29 09:42:15 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T const&)) {
	if (!array || length < 0 || !func)
		return ;
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}