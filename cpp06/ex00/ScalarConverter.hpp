/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:01:13 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/22 09:10:21 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarConverter {
private:
public:
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(ScalarConverter& other);
	ScalarConverter& operator=(ScalarConverter& other);
	static void convert(char *str);
};