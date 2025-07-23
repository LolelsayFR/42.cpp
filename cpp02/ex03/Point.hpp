/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:41:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/23 07:35:33 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;
public:
	Point();
	Point(float const x, float const y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};

#endif // POINT_HPP