/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:53:11 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 21:38:14 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "MutantStack contains:" << std::endl; // MutantStack contents
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	MutantStack<int>::iterator begin = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();
	std::cout << "MutantStack contains in end : " << *end << std::endl; // Last element
	std::cout << "MutantStack contains in begin : " << *begin <<  std::endl; // First element
	std::stack<int> s(mstack);
	return 0;
}