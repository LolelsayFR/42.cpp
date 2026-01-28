/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:57:26 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/28 10:31:47 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* Exception typedef */
/* ************************************************************************** */

errorException::errorException(std::string msg) throw(): msg(ERROR_PREFIX + msg) {};
const char* errorException::what(void) const throw() { return (this->msg.c_str()); };
errorException::~errorException() throw() {};

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
BitcoinExchange::BitcoinExchange() {
}

//  Assignation constructor
BitcoinExchange::BitcoinExchange(std::map<tm, double, compareDate> data) : dataMap(data) {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataMap(other.dataMap) {
}

// Default destructor
BitcoinExchange::~BitcoinExchange() {
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		dataMap = other.dataMap;
	}
	return (*this);
}

bool compareDate::operator()(const tm &x,const tm &y) const {
	if (x.tm_year != y.tm_year)
		return (x.tm_year < y.tm_year);
	if (x.tm_mon != y.tm_mon)
		return (x.tm_mon < y.tm_mon);
	return (x.tm_mday < y.tm_mday);
}

bool operator<(const tm &a, const tm &b) {
	if (a.tm_year != b.tm_year)
		return (a.tm_year < b.tm_year);
	if (a.tm_mon != b.tm_mon)
		return (a.tm_mon < b.tm_mon);
	return (a.tm_mday < b.tm_mday);
}

/* ************************************************************************** */
/* Other member function */
/* ************************************************************************** */

//line parser (format : date | value)
void BitcoinExchange::lineIter(std::string line, std::string context) {
	try {
		size_t sep = line.find('|');
		if (sep == std::string::npos || sep == 0)
			throw (errorException(E_MSG_BAD_INPUT + line + " (" + context + ")"));
		std::string	date = line.substr(0, sep);
		std::string	value = line.substr(sep + 1);
		if (value.empty())
			throw (errorException(E_MSG_BAD_INPUT + line + " (" + context + ")"));
		double resultValue = std::strtod(value.c_str(), NULL);
		if (resultValue < 0)
			throw (errorException(E_MSG_NEGATIVE_VALUE + std::string(" (" + context + ")")));
		if (resultValue > 1000)
			throw (errorException(E_MSG_TOO_LARGE_VALUE + std::string(" (" + context + ")")));
		tm date_tm = dateParser(date, context);
		if (this->dataMap.lower_bound(date_tm) == this->dataMap.end())
			std::cout << date << "=> " << resultValue << " = "  << (resultValue * (--this->dataMap.end())->second) << std::endl;
		else
			std::cout << date << "=> " << resultValue << " = "  << (resultValue * this->dataMap.lower_bound(date_tm)->second) << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

//printCsv
void BitcoinExchange::printCsv(void) {
	for (	std::map<tm, double, compareDate>::iterator it = this->dataMap.begin(); it != this->dataMap.end(); it++) {
		std::cout << "Date : " << it->first.tm_year << '-' << it->first.tm_mon << '-' << it->first.tm_mday << " Value : " << it->second << std::endl;
	}
}