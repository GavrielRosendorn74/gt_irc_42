/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:39:54 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/09 17:01:00 by grosendo         ###   ########.fr       */
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
		res += ((*cit)->getNickname() == _admin->getNickname() ? "@" : "+") + (*cit)->getNickname() + " ";
    }
	res.substr(0, res.length() - 1);
	return (res);
}

client_it  Channel::findClient(Client *client)
{
    for (client_it it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it)->getNickname() == client->getNickname())
			return (it);
	}
	return (_clients.end());
}

void    Channel::rmvClient(Client *client) 
{
    // _clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
    if (findClient(client) != _clients.end())
		_clients.erase(findClient(client));
    if (!(_clients.empty()))
    {
        /* if current client is admin -> set next client as admin */
        if (client == _admin)
        {
            _admin = _clients.begin().operator*(); /* set first client in channel clients as new admin  */
            _server->log(NEWCHANNELADMIN(_admin->getNickname())); /* log message */
        }

    }
    return ;
}

void    Channel::kick(Client *client, Client *target, std::string &comment)
{
    if (target)
    {
        rmvClient(target); /* remove client from channel first */
        //* REPLY() send message to channel -> client kicked + comment about it
        client->reply(RPL_KICK(client->prefix(), this->_name, target->getNickname(), comment));
        _server->log(CLIENTKICKED(client->getNickname()) + comment);
    }
}

void    Channel::broadcast(std::string const &message, Client *_to_exclude)
{
    vector<Client*>::iterator   cit = _clients.begin();
    for (; cit != _clients.end(); cit++)
	{
		if (_to_exclude != *cit)
			(*cit)->write(message);//RPL_PRIVMSG(_to_exclude->getNickname(), _name, message));
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