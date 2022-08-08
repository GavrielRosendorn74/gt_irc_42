/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:56:45 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 19:04:07 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "../Libraries.hpp"
#include "components/Channel.hpp"
#include "Server.hpp"

enum ClientRole {
	ANONYMOUS,
	CONNECTED
};

class Server; 

class Client 
{

private:
	int			_port;
	pollfd *	_pollfd;
	std::string _nickname;
	std::string _username;
	std::string _realname;
	std::string _hostname;
	
	ClientRole	_role;

	Server *	_server;

	Channel *	_channel;
	
public:
	/* Constructor & destructor */
	Client(int port, pollfd *fd, const std::string &hostname);
	~Client();

	/* getter */
	pollfd	*getFd() const {return _pollfd;}

	int getPort() const {return _port;}

	std::string getNickname() const {return _nickname;}
	std::string getUsername() const {return _username;}
	std::string getRealname() const {return _realname;}
	std::string	getHostname() const {return _hostname;}

	Channel *getChannel() const {return _channel;}

	/* Setter */
	void	setNickname(const std::string &nick) {_nickname = nick;}
	void	setUsername(const std::string &username) {_username = username;}
	void	setRealname(const std::string &realname) {_realname = realname;}
	void	setHostname(const std::string &host) {_hostname = host;}
	void	setRole(ClientRole role) {_role = role;}
	void	setChannel(Channel *channel) {_channel = channel;}

	/* other functions */
	bool 	isRegistered() const {return _role;}
	void	join(Channel *channel);
	void	welcomeMsg();
	void	quit();
};

#endif
