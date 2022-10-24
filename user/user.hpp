/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:13:12 by amontaut          #+#    #+#             */
/*   Updated: 2022/10/24 16:15:57 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <map>
#include <netinet/in.h>
#include "../channel/channel.hpp"

class User
{
private:
	std::map<bool, Channel> is_operator;
	std::map<bool, Channel> is_away; // ONLY IF on implemente la command AWAY
	std::map<bool, Channel> is_ban;
	std::map<bool, Channel> channels;
	std::map<std::string, bool> flags;
	std::string nickname;
	std::string username;
	std::string password;
	std::string hostname;
	struct sockaddr_in addr_usr;

public:
	User(std::string nickname, std::string username);
	User(User const &src);
	User &operator=(User const &rhs);
	~User(void);

	// getters if necessary
};

#endif