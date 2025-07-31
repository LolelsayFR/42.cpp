/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:26:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 09:07:50 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float barycentre (Point const &p1, Point const &p2, Point const &point)
{
	return 	(p1.getX() - point.getX()) * (p2.getY() - point.getY()) - 
			(p2.getX() - point.getX()) * (p1.getY() - point.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool b1, b2, b3;

    b1 = barycentre(a, b, point) <= 0 ;
    b2 = barycentre(b, c, point) <= 0;
    b3 = barycentre(c, a, point) <= 0 ;

    return ((b1 == b2) && (b2 == b3));
}

/* ************************************************************************** */
/*	Source link : 															  */
/*		https://www.youtube.com/watch?v=kkucCUlyIUE				 			  */
/*		https://ifdesignelseart.com/?p=306 									  */
/* ************************************************************************** */