/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:13:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/24 10:53:51 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <sstream>
//itoa lib
#include <cstdlib>
#include <cstring>



ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter&other) {(void)other;}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter&other) {(void)other; return (*this);}



bool isChar(std::string s) {
	char*	stash = NULL;
	double	value = std::strtod(s.c_str(), &stash);

	//std::cout << "Value: " << value << std::endl;
	//std::cout << "Stash: " << stash << std::endl;
	//std::cout << "String: " << s << std::endl;
	//std::cout << "Value round unit : " << value / 1 << std::endl;

	if (s[1] == '\0')
		return (true);
	else if (isascii(value) && (std::string(stash).empty() || (stash[0] == 'f'	&& stash[1] == '\0')) && value == (int)value)
		return (true);
	return (false);
}

//bool isInt(std::string s) {
//	return (false);
//}

//bool isFloat(std::string s) {
//	return (false);
//}

//bool isDouble(std::string s) {
//	return (false);
//}

void ScalarConverter::convert(char* str) {
	{//CHAR CONVERSION
		if (isChar(str) && ((str[1] == '\0' && !std::isprint(str[0])) || (str[1] != '\0' && !std::isprint(std::strtod(str, NULL)))))
			std::cout << "Char: Non displayable" << std::endl;
		else if (isChar(str) && str[1] == '\0') 
			std::cout << "Char: '" << static_cast<char>(str[0]) << "'" << std::endl;
		else if (isChar(str))
			std::cout << "Char: '" << static_cast<char>(std::strtod(str, NULL) / 1) << "'" << std::endl;
		else if (isChar(str) == false)
			std::cout << "Char: impossible" << std::endl;
	}
	{//INT CONVERSION
		if (1)
			std::cout << "Int: " << static_cast<int>(std::strtod(str, NULL) / 1) << std::endl;
		else
			std::cout << "Int: impossible" << std::endl;
	}
	{//FLOAT CONVERSION
		if (1)
			std::cout << "Float: " << static_cast<float>(std::strtod(str, NULL)) << "f" << std::endl;
		else
			std::cout << "Float: impossible" << std::endl;
	}
	{//DOUBLE CONVERSION
		if (1)
			std::cout << "Double: " << static_cast<double>(std::strtod(str, NULL)) << std::endl;
		else
			std::cout << "Double: impossible" << std::endl;
	}
}