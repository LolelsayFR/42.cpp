/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:01:13 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 09:58:31 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdint.h>	
#include <iostream>


struct Data {
	Data(std::string a, std::string t, std::string c);
	std::string author;
	std::string title;
	std::string content;
};


class Serializer {
public:
	Serializer(void);
	~Serializer(void);
	Serializer(Serializer& other);
	Serializer& operator=(Serializer& other);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& os, const Data& fable);