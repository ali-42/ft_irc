/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:13:12 by amontaut          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:20 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
#define REPLY_HPP

#include <iostream>
#include <list>

class Reply
{
private:
	std::string prefix;
	std::string command; //int or string ? because 001 as int will be 1
	std::string param1; //= nick so maybe not usefull here to have 1 more attributes (duplicate)
	std::list<std::string> param2;

public:
	Reply(std::string prefix, std::string command);
	Reply(Reply const &src);
	Reply &operator=(Reply const &rhs);
	~Reply(void);
	// getters if necessary
};

#endif