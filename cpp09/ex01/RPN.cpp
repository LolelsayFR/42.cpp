/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:18:43 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 04:53:51 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
RPN::RPN() {
}

// Copy constructor
RPN::RPN(const RPN& other) : stack(other.stack) {
}

// Default destructor
RPN::~RPN() {
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
RPN& RPN::operator=(const RPN& other) {
	this->stack = other.stack;
	return (*this);
}

/* ************************************************************************** */
/* all other member function */
/* ************************************************************************** */

void RPN::calculate(std::string calcul) {
	int l, r;
	for (int i = 0; calcul[i]; i++) {
		if (isdigit(calcul[i]))
			this->stack.push(calcul[i] - '0');
		else if (strchr("-+/*", calcul[i])) {
			if (this->stack.size() < 2) { std::cerr << ERROR_PREFIX << E_MSG_BAD_INPUT << std::endl; return; }
			r = this->stack.top(); this->stack.pop(); 
			l = this->stack.top(); this->stack.pop(); 
		}
		switch (calcul[i])
		{
			case '-':
				this->stack.push(l - r);
				break;
			case '+':
				this->stack.push(l + r);
				break;
			case '/':
				if (r == 0) {std::cerr << ERROR_PREFIX << E_MSG_DIV_ZERO << std::endl; return; };
				this->stack.push(l / r);
				break;
			case '*':
				this->stack.push(l * r);
				break;
			default:
				break;
		}
	}
	if (stack.size() > 1) {
		std::cout << "Unused : ";
		while (stack.size() > 1) {std::cout << this->stack.top() << " "; this->stack.pop();}
		std::cout << std::endl;
	}
	std::cout << this->stack.top() << std::endl;
}

bool RPN::verify(std::string calcul) {
	int digit = 0, op = 0;
	for (int i = 0; calcul[i]; i++) {
		if (!isdigit(calcul[i]) && !strchr("-+/* ", calcul[i]))
			return (false);
		else if (isdigit(calcul[i]))
			digit++;
		else if (strchr("-+/*", calcul[i])) 
			op++;
	}
	if (digit != op + 1)
		return (false);
	return (true);
}