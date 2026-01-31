/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:33:16 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 07:20:08 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ************************************************************************** */
/* Includes et defines */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <limits.h>

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
	std::string vecSort(void);
	std::string dequeSort(void);
	std::string printSort();
	~PmergeMe();
};

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */