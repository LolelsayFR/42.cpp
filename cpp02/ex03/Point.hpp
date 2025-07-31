/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:41:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 08:11:00 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(float const x, float const y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	float getX(void) const;
	float getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
