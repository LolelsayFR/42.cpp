/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:37 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 12:30:59 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> T const& min(T const& a, T const& b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T const& max(T const& a, T const& b) {
	if (a > b)
		return (a);
	return (b);
}