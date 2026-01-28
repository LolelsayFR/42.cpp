/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:29 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/28 10:32:00 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* Utils function */
/* ************************************************************************** */

// https://www.gladir.com/CODER/CPP/isleapyear.htm
int IsLeapYear(int year) {
    return ((year & 3) == 0) && (((year % 100) != 0) || ((year % 400) == 0));
}

bool isDateValid(int y, int m, int d) {
	if (m < 1 || m > 12 || d < 1)
		return (false);
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(y))
		daysInMonth[1] = 29;
	if (d > daysInMonth[m - 1])
		return (false);
	return (true);
}

tm dateParser(std::string date, std::string context) {
	int i = 0, c = 0;
	if (date[date.length() - 1] == ' ')
		date.erase(date.length() - 1);
	std::string	dateValue[3];
	dateValue[0] = date.substr(0, date.find('-', 1));
	dateValue[1] = date.substr(date.find('-', 1) + 1, date.rfind('-') - date.find('-', 1) - 1);
	dateValue[2] = date.substr(date.rfind('-') + 1, date.length() - date.rfind('-') - 1);
	if (date[0] == '-')
		i = 1;
	while (date[i]) {
		if (date[i] == '-')
			c++;
		i++;
	}
	if (c != 2 || 
		dateValue[1].length() != 2 ||
		dateValue[2].length() != 2 ||
		!isDateValid(atoi(dateValue[0].c_str()), atoi(dateValue[1].c_str()), atoi(dateValue[2].c_str())))
		throw (errorException(E_MSG_BAD_INPUT + date + " (" + context + ")"));
	tm result;
	result.tm_year = atoi(dateValue[0].c_str());
	result.tm_mon = atoi(dateValue[1].c_str());
	result.tm_mday = atoi(dateValue[2].c_str());
	return (result);
}

//csv parser (format : date,exchange_rate)
BitcoinExchange csvParser(void) {
	std::map<tm, double, compareDate> valueMap;

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
		tm resultDate = dateParser(date, std::string(CSVPATH));
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
		if (argc != 2)
			throw (errorException("Invalid number of arguments"));
		std::ifstream file(argv[1]);
		std::string	line;
		if (!file.is_open())
			throw (errorException("Could not open file : " + std::string(argv[1])));
		std::string inputFilePath = argv[1];
		BitcoinExchange btc = csvParser();
		btc.printCsv();
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