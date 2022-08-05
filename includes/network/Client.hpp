/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:56:45 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 08:10:08 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <vector>
#include <iostream>
#include <poll.h>

#ifndef CLIENT_HPP
# define CLIENT_HPP

enum ClientRole {
	ANONYMOUS,
	CONNECTED,
	OPERATOR,
	DISCONNECTED
};

class Client 
{

private:
	int _port;
	pollfd		_pollfd;
	std::string _nickname;
	std::string _username;
	std::string _realname;
	ClientRole	_role;
	Server *	_server;
public:
	Client(int port);
	~Client();
};

#endif
