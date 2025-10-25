/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:56:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 10:28:02 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data		*data = new Data("Jean de La Fontaine", "The Fox and the Crow", "Once upon a time...");
	Serializer	serializer;

	std::cout << *data;
	uintptr_t serializedData = serializer.serialize(data);
	data->content = "This content has been changed.";
	std::cout << "Addresse : " << data << " or " << (uintptr_t)data << "\n";
	std::cout << "Serialized Data (as uintptr_t): " << serializedData << "\n\n";
	Data *deserializedData = serializer.deserialize(serializedData);
	std::cout << "Deserialized Addresse : " << deserializedData << " or " << (uintptr_t)deserializedData << "\n";
	std::cout << *deserializedData;

	delete data;
	return (0);
}