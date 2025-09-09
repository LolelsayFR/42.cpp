/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/12 01:23:42 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define SUFFIX ".replace"

std::string	ft_replace(std::string content, std::string search, std::string replace)
{
	int 		pos;
	std::string result;

	pos = content.rfind(search);
	if (search.size() <= 0 || pos < 0)
		return (content);	
	while (pos >= 0)
	{
		result = replace + content.substr(pos + (int)search.size()) + result;
		content.erase(pos);
		pos = content.rfind(search);
	}
	result = content + result;
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Usage: " << av[0] << " <filename> <search> <replace>" << std::endl, 0);
	std::fstream myFile (av[1]);
	std::string myNewFileName = (std::string)av[1] + SUFFIX;
	std::ofstream myNewFile(myNewFileName.c_str());
	std::string myContent;
	std::string myLine;
	if (myFile.is_open())
	{
		while (getline(myFile, myLine) )
			myContent += myLine + '\n';
		myFile.close();
	}
	else 
		std::cout << "Unable to open new file" << std::endl;
	if (myNewFile.is_open())
	{
		myNewFile << ft_replace(myContent, (std::string)av[2], (std::string)av[3]);
		myNewFile.close();
	}
	else 
		std::cout << "Unable to open file source" << std::endl;
	return (0);
}
