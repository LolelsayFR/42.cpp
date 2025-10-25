/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:13:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 09:03:49 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cfloat>


ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter&other) {(void)other;}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter&other) {(void)other; return (*this);}



bool isChar(std::string s) {
	char*	stash = NULL;
	double	value = std::strtod(s.c_str(), &stash);

	if (s[1] == '\0' && !std::isdigit(s[0]) && isascii(s[0]))
		return (true);
	else if (isascii(value) && (std::string(stash).empty() || (stash[0] == 'f'	&& stash[1] == '\0')) && value == (int)value)
		return (true);
	return (false);
}

void ScalarConverter::convert(char* str) {
	char*	stash = NULL;

	{//CHAR CONVERSION
		if (isChar(str) && str[1] == '\0' && str[0] != '\0' && !std::isdigit(str[0])) {
			if (std::isprint(static_cast<char>(str[0])))
				std::cout << "Char   : '" << static_cast<char>(str[0]) << "'" << std::endl;
			else
				std::cout << "Char   : Non displayble" << std::endl;
		}
		else if (isChar(str)) {
			if (std::isprint(static_cast<char>(std::strtod(str, NULL))))
				std::cout << "Char   : '" << static_cast<char>(std::strtod(str, NULL)) << "'" << std::endl;
			else
				std::cout << "Char   : Non displayble" << std::endl;
		}
		else if (isChar(str) == false)
			std::cout << "Char   : impossible" << std::endl;
	}
	{//INT CONVERSION
		long l = static_cast<long>(std::strtol(str, &stash, 10));
		if (l < INT_MIN || l > INT_MAX)
			std::cout << "Int    : impossible (overflow)" << std::endl;
		else {
			int i = static_cast<int>(std::strtod(str, &stash));
			if (stash[0] == '\0' || (stash[0] == 'f' && stash[1] == '\0'))
				std::cout << "Int    : " << i << std::endl;
			else
				std::cout << "Int    : impossible" << std::endl;
		}
	}
	{//FLOAT CONVERSION
		float f = static_cast<float>(std::strtof(str, &stash));
		if (stash[0] == '\0' || (stash[0] == 'f' && stash[1] == '\0'))
			std::cout << "Float  : " << f << 'f' << std::endl;
		else
			std::cout << "Float  : impossible" << std::endl;
	}
	{//DOUBLE CONVERSION
		double d = static_cast<double>(std::strtod(str, &stash));
		if (stash[0] == '\0' || (stash[0] == 'f' && stash[1] == '\0'))
			std::cout << "Double : " << d << std::endl;
		else
			std::cout << "Double : impossible" << std::endl;
	}
}