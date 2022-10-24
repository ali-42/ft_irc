/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:20:02 by ali               #+#    #+#             */
/*   Updated: 2022/10/24 13:54:17 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

class Server
{
	private:
		std::map<int, User>	users;
		std::map<std::string, Channel>	channels;
		std::vector<struct pollfd>	pfds;
		struct	sockaddr_in	addr;

	public:
		Server(int port);
		initServ();
		updateInternals(Command& cmd);
		sendReply(Command& cmd);
		addUser(int socket, User &user);
		addChannel(std::string name);
};

#endif
