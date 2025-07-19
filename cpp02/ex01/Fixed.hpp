/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:07:34 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 15:05:32 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _number;
	static const int    _nBits = 8;
public:
	Fixed();
	Fixed(int const i);
	Fixed(float const f);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	friend std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif // FIXED_HPP