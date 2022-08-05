/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:56:45 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 09:32:42 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "../Libraries.hpp"
#include "components/Channel.hpp"
#include "Server.hpp"

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
