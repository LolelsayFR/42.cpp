/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:18:07 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 17:37:14 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUGDEBUG");
	harl.complain("INFOINFO");
	harl.complain("WARNINGWARNING");
	harl.complain("ERRORERROR");
	harl.complain("DALTON");
	harl.complain("INFINITY");
	harl.complain("WALUIGI");
	harl.complain("Emilien");
	harl.complain("");
	return (0);
}
