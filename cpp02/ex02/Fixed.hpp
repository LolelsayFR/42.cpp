/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:07:34 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/23 08:10:08 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _rawBits;
	static const int    _nBits = 8;
public:
	Fixed();
	Fixed(int const i);
	Fixed(float const f);
	Fixed(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=(const Fixed& other);
	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	Fixed&	operator++();   
	Fixed	operator++(int); 
	Fixed&	operator--();   
	Fixed	operator--(int);

	bool		operator==(const Fixed& other);
	bool		operator!=(const Fixed& other);
	bool		operator< (const Fixed& other);
	bool		operator> (const Fixed& other);
	bool		operator<=(const Fixed& other);
	bool		operator>=(const Fixed& other);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};


std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);

#endif // FIXED_HPP