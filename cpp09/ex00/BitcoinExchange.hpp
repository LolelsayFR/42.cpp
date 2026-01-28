/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:56:23 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/28 10:11:32 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Sources */
/* ************************************************************************** */

//https://en.cppreference.com/w/cpp/chrono/c/tm.html

/* ************************************************************************** */
/* Includes et defines */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

#define CSVPATH "./data.csv"
#define ERROR_PREFIX "Error : "
#define E_MSG_BAD_INPUT "Bad input => "
#define E_MSG_NEGATIVE_VALUE "Negative value"
#define E_MSG_TOO_LARGE_VALUE "Value too large"

/* ************************************************************************** */
/* Exception */
/* ************************************************************************** */

class errorException : public std::exception {
public:
	std::string msg;
	errorException(std::string msg) throw();
	const char* what(void) const throw();
	virtual ~errorException() throw();
private :
	errorException();
};

/* ************************************************************************** */
/* Struct & Class */
/* ************************************************************************** */

// simple comparison function
struct compareDate {
	bool operator()(const tm &x, const tm &y) const;
};


class BitcoinExchange
{
private:
	std::map<tm, double, compareDate> dataMap;
	BitcoinExchange();
public:
	BitcoinExchange(std::map<tm, double, compareDate> data);
	BitcoinExchange(std::map<tm, double> data);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void lineIter(std::string line, std::string context);
	void printCsv(void);
};

/* ************************************************************************** */
/* Other */
/* ************************************************************************** */

tm dateParser(std::string date, std::string context);
bool operator<(const tm &a, const tm &b);

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */
