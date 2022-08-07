/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:18:31 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/07 07:35:17 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network/Server.hpp"
#include "../../includes/Libraries.hpp"

Server::Server(const string &port, const string &password)
{
	_option = 1;
	// VERRIFY PORT
	if (port.length() == 0)
		throw Exception::invalid_port();
	string::const_iterator it = port.begin();
	while (it != port.end()) 
	{
		if(!isdigit(*it))
			throw Exception::invalid_port_format();
		it++;
	}
	// INSTALL
	_port = atoi(port.c_str());
	_password = password;
}

Server::~Server(){};

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
	log("IRC socket is up !");
	return (this);
}

void		Server::log(string message)
{
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

	cout << PINK << buf << " | " << BLUE << message << DEFAULT << endl;
}

void		Server::live()
{
	// WE ADD SEVER_FD TO THE LIST TO LISTEN
	pollfd server_fd = {_sock_fd, POLLIN, 0};
	_fds.push_back(server_fd);

	log("IRC started and listening on port " + ft_itoastr(_port));
	while (1) {

		// We make poll on the open fds to wait for an event
		if (poll(_fds.begin().base(), _fds.size(), -1) < 0)
			throw std::runtime_error("Error while polling from fd.");

		// We are verrify on each fd if the event is comming from him
		for (poll_it it = _fds.begin(); it != _fds.end(); it++) {

			if (it->revents == 0)
				continue;

			if (it->revents == POLLHUP) {
				//DISCONNECT
				//onClientDisconnect(it->fd);
				break;
			}

			if (it->revents == POLLIN) {

				if (it->fd == _sock_fd) {
					log("Welcome to our server !");
					//onClientConnect();
					break;
				}

				//onClientMessage(it->fd);
			}
		}
	}
}