/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:57:26 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/28 12:40:18 by emaillet         ###   ########.fr       */
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

bool operator==(const tm &a, const tm &b) {
	if (a.tm_year != b.tm_year)
		return (false);
	if (a.tm_mon != b.tm_mon)
		return (false);
	return (a.tm_mday == b.tm_mday);
}

/* ************************************************************************** */
/* Other member function */
/* ************************************************************************** */

//print util
void printResult(tm date, int base, double value) {
			std::cout << std::setw(4) << std::setfill('0') << date.tm_year << '-'
				<< std::setw(2) << std::setfill('0') << date.tm_mon << '-'
				<< std::setw(2) << std::setfill('0') << date.tm_mday
				<< " => " << base << " = " << value << std::endl;
}

//Value finder
double BitcoinExchange::findDate(tm date) {
	for (std::map<tm, double, compareDate>::iterator it = this->dataMap.begin(); it != this->dataMap.end(); it++) {
		if (date == it->first || (date < it->first && it == this->dataMap.begin()))
			return ((it)->second);
		if (date < it->first)
			return ((--it)->second);
	}
	return ((--this->dataMap.end())->second);
}

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
		char* stash;
		double resultValue = std::strtod(value.c_str(), &stash);
		if (!std::string(stash).empty())
			throw (errorException(E_MSG_BAD_INPUT + line + " (" + context + ")"));
		if (resultValue < 0)
			throw (errorException(E_MSG_NEGATIVE_VALUE + std::string(" (" + context + ")")));
		if (resultValue > 1000)
			throw (errorException(E_MSG_TOO_LARGE_VALUE + std::string(" (" + context + ")")));
		tm date_tm = dateParser(date, context);
		printResult(date_tm, resultValue, resultValue * findDate(date_tm));
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