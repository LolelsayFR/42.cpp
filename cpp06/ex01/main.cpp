/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:56:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/27 09:14:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data		*data = new Data("Jean de La Fontaine", "The Fox and the Crow", "Once upon a time...");

	std::cout << *data << std::endl; // Data print
	uintptr_t serializedData = Serializer::serialize(data);
	data->author = "Bernard";
	Data *deserializedData = Serializer::deserialize(serializedData);
	std::cout << *deserializedData; // Data print deserialize

	delete deserializedData;
	return (0);
}