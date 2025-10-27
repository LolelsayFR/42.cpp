/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:13:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/27 08:53:59 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Data::Data(std::string a, std::string t, std::string c) : author(a), title(t), content(c) {}

std::ostream& operator<<(std::ostream& os, const Data& data) {
	os << "Author: " << data.author << "\n"
	   << "Title: " << data.title << "\n"
	   << "Content: " << data.content << "\n";
	return (os);
}

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer&other) {(void)other;}

Serializer::~Serializer(void) {}

Serializer& Serializer::operator=(Serializer&other) {(void)other; return (*this);}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
