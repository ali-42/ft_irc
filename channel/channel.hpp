/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:13:12 by amontaut          #+#    #+#             */
/*   Updated: 2022/10/24 16:14:30 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>
#include "../user/user.hpp"

class Channel
{
private:
	std::vector<User> users;
	std::string name;
	std::string password;
	std::map<std::string, bool> flags;
	int	max_clients;

public:
	Channel(std::string name);
	Channel(Channel const &src);
	Channel &operator=(Channel const &rhs);
	~Channel(void);

	// getters if necessary
};

#endif