/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:39:54 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/09 08:34:42 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/network/components/Channel.hpp"

Channel::Channel(const std::string &name, Client *admin) : _name(name), _admin(admin) {}

Channel::~Channel() {}

std::string     Channel::getName() {return _name;} /* return name of current channel */

std::vector<Client*>    *Channel::getClients() {return &_clients;} /* return all members of current channel under the form of a vector */

Client *Channel::getAdmin() {return _admin;} /* get the current channel admin */

void    Channel::addClient(Client *client) {_clients.push_back(client);}

string	Channel::getClientsStr()
{
	string res = "";
	vector<Client*>::iterator cit = this->_clients.begin();
    for (; cit != _clients.end(); cit++)
    {
		res += "+" + (*cit)->getNickname() + " ";
    }
	return (res);
}

void    Channel::rmvClient(Client *client) 
{
    _clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
    if (!(_clients.empty()))
    {
        /* if current client is admin -> set next client as admin */
        if (client == _admin)
        {
            _admin = _clients.begin().operator*(); /* set first client in channel clients as new admin  */
            //* REPLY() send message to channel -> new admin 
            _server->log(NEWCHANNELADMIN(_admin->getNickname())); /* log message */
        }

    }
    _server->removeChannel(this); /* remove channel from server */
    free(this); /* free current channel */
    return ;
}

void    Channel::kick(Client *client, Client *target, std::string &comment)
{
    rmvClient(target); /* remove client from channel first */
    //* REPLY() send message to channel -> client kicked + comment about it
    _server->log(CLIENTKICKED(client->getNickname()) + comment);
}

void    Channel::broadcast(std::string const &message, Client *_to_exclude)
{
    vector<Client*>::iterator   cit = _clients.begin();
    for (; cit != _clients.end(); cit++)
	{
		if (_to_exclude != *cit)
			(*cit)->write(message);
	}
    _server->log(MSGBROADCASTEDTOCHANNEL(message));
}

bool    Channel::isCLientInChannel(Client *client)
{
    vector<Client*>::iterator cit = this->_clients.begin();
    for (; cit != _clients.end(); cit++)
    {
        if ((*cit)->getNickname() == client->getNickname())
            return true;
    }
    return false;
}