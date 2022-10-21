/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:38:08 by ali               #+#    #+#             */
/*   Updated: 2022/10/21 13:24:12 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netinet/ip.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
using namespace std;


int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in	servaddr;

	bzero((char*)&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6667);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sock, (sockaddr*)&servaddr, sizeof(servaddr));

	listen(sock, 5);
	sockaddr_in	new_servaddr;

	socklen_t new_servaddr_size = sizeof(new_servaddr);
	
	int newsock = accept(sock, (sockaddr*)&new_servaddr, &new_servaddr_size);

	char buffer[4000];
	int	bytes;
	while (1)
	{
		bytes = recv(newsock, buffer, sizeof(buffer), 0);
		if (bytes)
			cout << buffer << endl;
	}
}
