/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:53:48 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/09 15:07:59 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network/Client.hpp"

Client::Client(int port, pollfd fd, const std::string &hostname) : _port(port), _pollfd(fd), _hostname(hostname) {
	_nickname = "";
	_role = ANONYMOUS;
}

Client::~Client() {}

void    Client::join(Channel *channel)
{
    channel->addClient(this);

    //* get channe users function -> store it in a vector  */

    //* announce to channel that this client user has arrived */
}

void    Client::welcomeMsg()
{
	_server->log("WELCOME ENTERED");
    if (_username.empty() || _nickname.empty() || _realname.empty()) {
		return ;
	}
        //* REPLY() error empty nick or realname or username
	
    _role = CONNECTED;
	_server->log("WELCOME CONNECTED");
	write(RPL_WELCOME(_nickname));
    //* display welcome message HERE
    //* user now know as "NEW NICKNAME"
}

void    Client::quit()
{
    //_channel->rmvClient(this); /* remove client from this channel */
    
    //* REPLY() no channel to quit
    return;	
}

void    Client::write(const std::string &message) const
{
    std::string buff = message + "\r\n";
	if (send(_pollfd.fd, buff.c_str(), buff.length(), 0) > 0)
        _server->log(MSG_SENT);
    else
        _server->log(ERR_MSG_NOT_SENT);
}

std::string Client::prefix() const 
{
    return _nickname + (_username.empty() ? "" : "!" + _username) + (_hostname.empty() ? "" : "@" + _hostname);
}

void    Client::reply(const std::string &reply) const
{
    this->write(":" + prefix() + " " + reply);
}