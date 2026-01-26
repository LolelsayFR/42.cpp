/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:29 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/26 16:31:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* Utils function */
/* ************************************************************************** */

std::string dateParser(std::string date, std::string context) {
	if (date[date.length() - 1] == ' ')
		date.erase(date.length() - 1);
	std::string	dateValue[3];
	dateValue[0] = date.substr(0, date.find('-'));
	dateValue[1] = date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1);
	dateValue[2] = date.substr(date.rfind('-') + 1, date.length() - date.rfind('-') - 1);

	if (dateValue[0].length() != 4 || 
		dateValue[1].length() != 2 || 
		dateValue[2].length() != 2)
		throw (errorException(E_MSG_BAD_INPUT + date + "(" + context + ")"));

	return (date);
}

//csv parser (format : date,exchange_rate)
BitcoinExchange csvParser(void) {
	std::map<std::string, double> valueMap;

	std::ifstream file(CSVPATH);
	std::string	line;
	int i = 0;

	if (!file.is_open())
		throw (errorException("Could not open file : " + std::string(CSVPATH)));
	getline(file, line);
	if (line != "date,exchange_rate")
		throw (errorException("Invalid csv header : " + std::string(CSVPATH)));
	while (getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos || commaPos == 0)
			throw (errorException("CSV parsing error : " + line + " -> " + std::string(CSVPATH)));
		std::string	date = line.substr(0, commaPos);
		std::string	value = line.substr(commaPos + 1);
		if (date.empty() || value.empty())
			throw (errorException("CSV parsing error : " + line + " -> " + std::string(CSVPATH)));
		std::string resultDate = dateParser(date, std::string(CSVPATH));
		double resultValue = std::strtod(value.c_str(), NULL);
		valueMap[resultDate] = resultValue;
		i++;
	}
	return (BitcoinExchange(valueMap));
}


/* ************************************************************************** */
/* Main */
/* ************************************************************************** */
int main(int argc, char const *argv[])
{
	std::cout.precision(10);
	try {
		std::ifstream file(argv[1]);
		std::string	line;
		if (!file.is_open())
			throw (errorException("Could not open file : " + std::string(argv[1])));
		if (argc != 2)
			throw (errorException("Invalid number of arguments"));
		std::string inputFilePath = argv[1];
		BitcoinExchange btc = csvParser();
		//btc.printCsv();
		getline(file, line);
		if (line != "date | value")
			throw (errorException("Invalid txt header : " + std::string(argv[1])));
		while (getline(file, line))
			btc.lineIter(line, argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}