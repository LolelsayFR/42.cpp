/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:33:16 by emaillet          #+#    #+#             */
/*   Updated: 2026/02/02 09:53:43 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ************************************************************************** */
/* Includes et defines */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <iomanip>

#define CSVPATH "./data.csv"
#define ERROR_PREFIX "Error: "
#define E_MSG_NBARG "invalid arg's number."
#define E_MSG_BAD_INPUT "bad input."

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
/* Class */
/* ************************************************************************** */

class PmergeMe
{
private:
	std::deque<unsigned int> deque;
	std::vector<unsigned int> vector;
	PmergeMe();
public:
	PmergeMe(char** argv);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	void vecSort(void);
	void dequeSort(void);
	~PmergeMe();
};

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */