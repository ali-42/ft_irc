/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:13:12 by amontaut          #+#    #+#             */
/*   Updated: 2022/10/24 16:04:24 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <list>

class Command
{
private:
	std::string prefix;
	std::string command;
	std::list<std::string> params;

public:
	Command(std::string command);
	Command(Command const &src);
	Command &operator=(Command const &rhs);
	~Command(void);

	// getters if necessary
};

#endif