/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:26:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/02 19:00:31 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float relativePosition (Point const &p1, Point const &p2, Point const &point)
{
    float x1 = p1.getX();
    float y1 = p1.getY();
    float x2 = p2.getX();
    float y2 = p2.getY();
    float x  = point.getX();
    float y  = point.getY();

    return (x1 - x) * (y2 - y) - (x2 - x) * (y1 - y);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool b1, b2, b3;

    b1 = relativePosition(a, b, point) <= 0 ;
    b2 = relativePosition(b, c, point) <= 0;
    b3 = relativePosition(c, a, point) <= 0 ;

    return ((b1 == b2) && (b2 == b3));
}

/* ************************************************************************** */
/*	Source link : 															  */
/*		https://www.youtube.com/watch?v=kkucCUlyIUE				 			  */
/*		https://ifdesignelseart.com/?p=306 									  */
/* ************************************************************************** */