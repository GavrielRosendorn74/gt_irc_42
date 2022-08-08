/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:18:31 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 23:29:47 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"
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



void Server::_onClientConnect() {
	int fd;
	sockaddr_in s_address = {};
	socklen_t s_size = sizeof(s_address);

	fd = accept(_sock_fd, (sockaddr *) &s_address, &s_size);
	if (fd < 0)
		throw Exception::accept_failure();

	pollfd pollfd = {fd, POLLIN, 0};
	_fds.push_back(pollfd);

	char hostname[NI_MAXHOST];
	if (getnameinfo((struct sockaddr *) &s_address, sizeof(s_address), hostname, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) !=0)
		throw std::runtime_error("Error while getting hostname on new client.");

	Client *client = new Client(ntohs(s_address.sin_port), &(*(_fds.end() - 1)), hostname);
	_clients.push_back(client);

	log("New client connected on port : " + ft_itoastr(client->getPort()));
}


void Server::_onClientDisconnect(Client *client) {
		log("CLIENT DISCONNECT");
		client->quit();
		_clients.erase(findClient(client));
		_fds.erase(findFd(*(client->getFd())));
		log("Client connected on port " + ft_itoastr(client->getPort()) + " left !");
		delete client;
}

client_it Server::findClient(Client *client) 
{
	for (client_it it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it) == client)
			return (it);
	}
	return (_clients.end());
}

Client * Server::findClientByFd(pollfd fd) 
{
	for (client_it it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it)->getFd()->fd == fd.fd)
			return (*it);
	}
	return (NULL);
}

Client * Server::findClientByNickname(string nickname) 
{
	for (client_it it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it)->getNickname() == nickname) 
			return (*it);
	}
	return (NULL);
}

poll_it Server::findFd(pollfd fd) 
{
	for (poll_it it = _fds.begin(); it != _fds.end(); it++) {
		if ((*it).fd == fd.fd)
			return (it);
	}
	return (_fds.end());
}

string		Server::getPassword()
{
	return _password;
}

vector<Client *>	Server::getClients()
{
	return _clients;
}

void		Server::removeChannel(Channel *channel)
{
	
}

void		Server::_onClientMessage(Client *client)
{
	string message = _readMessageOfClient(client);
	// WARNING
	log(client->getNickname() + " has sent " + message.substr(0, message.length() - 1));
	// BREAK IF MANY LINES
	while (message.find('\n') != string::npos || message.find('\r') != string::npos)
	{
		// SKIP /R/N
		int index = 0;
		while (message[index] == '\n' || message[index] == '\r') index++;
		message = message.substr(index);
		if (message.length() == 0)
			break ;
		// EXEC
		size_t i = (message.find('\n') != string::npos) ? message.find('\n') : message.find('\r');
		if ((message.find('\n') != string::npos && message.find('\r') != string::npos) && message.find('\r') < message.find('\n'))
			i = message.find('\r');
		Command * command = new Command(this, client);
		command->build(message.substr(0, i))
			->execute();
		delete command;	
		message = message.substr(i);
	}
}

string		Server::_readMessageOfClient(Client *client)
{
	std::string message;

	char buffer[101];
	bzero(buffer, 101);

	while (!strstr(buffer, "\r\n")) {
		bzero(buffer, 100);
		if (recv(client->getFd()->fd, buffer, 100, 0) < 0) {
			if (errno != EWOULDBLOCK)
				throw std::runtime_error("Error while reading buffer from client.");
		}
		message.append(buffer);
	}

	return message;
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

			if ((it->revents & POLLHUP) == POLLHUP) {
				//DISCONNECT
				_onClientDisconnect(findClientByFd(*it));
				break;
			}

			if ((it->revents & POLLIN) == POLLIN) {

				if (it->fd == _sock_fd) {
					_onClientConnect();
					break;
				}

				_onClientMessage(findClientByFd(*it));
			}
		}
	}
}