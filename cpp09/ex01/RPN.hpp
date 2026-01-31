/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:20:17 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 04:53:34 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

#define CSVPATH "./data.csv"
#define ERROR_PREFIX "Error: "
#define E_MSG_NBARG "invalid arg's number."
#define E_MSG_BAD_INPUT "bad input."
#define E_MSG_DIV_ZERO "division by zero."

/* ************************************************************************** */
/* Class */
/* ************************************************************************** */


class RPN
{
private:
	std::stack<int> stack;
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	void calculate(std::string calcul);
	bool verify (std::string calcul);
};

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */