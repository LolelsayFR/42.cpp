/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:34:08 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 21:54:00 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

//Stack is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
//By default, the underlying container to use is std::deque.

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    virtual ~MutantStack() {}

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    // Typedef pour l'itérateur (C++98 compliant)
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Fonctions membres pour les itérateurs
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

};

#endif