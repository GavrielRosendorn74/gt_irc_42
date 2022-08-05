/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:18:31 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 10:26:09 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network/Server.hpp"

Server::Server(const string &port, const string &password)
{
	_option = 1;
	_port = atoi(port.c_str());
	_password = password;
}

Server * Server::launch()
{
	// Creating a master socket
	if ((_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0)
		throw Exception::socket_creation_failure();
	// set socket to handle multiple connections
	if (setsockopt(_sock_fd, SOL_SOCKET, SO_REUSEADDR, &_option, sizeof(_option)) < 0)
		throw Exception::socket_config_failure();
	// Set socket to non blocking
	if (fcntl(_sock_fd, F_SETFL, O_NONBLOCK) == -1)
		throw Exception::socket_non_blocking_failure();
	// Define the socket type 
	struct sockaddr_in		_address = {};
	bzero((char *) &_address, sizeof(_address));
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(_port);
	// Bind the socket to port
	if (bind(_sock_fd, (struct sockaddr *)&_address, sizeof(_address)) < 0)
		throw Exception::binding_failure();
	if (listen(_sock_fd, 3) < 0)
		throw Exception::listening_failure();
	// finally, accept incomming connections
	cout << "Waiting for connections...\n";
	return (this);
}

void		Server::live()
{
	
}