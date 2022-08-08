/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:39:54 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/08 22:31:23 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network/components/Channel.hpp"

Channel::Channel(const std::string &name, Client *admin) : _name(name), _admin(admin) {}

Channel::~Channel() {}

std::string     Channel::getName() {return _name;} /* return name of current channel */

std::vector<Client*>    *Channel::getClients() {return &_clients;} /* return all members of current channel under the form of a vector */

Client *Channel::getAdmin() {return _admin;} /* get the current channel admin */

void    Channel::addClient(Client *client) {_clients.push_back(client);}

void    Channel::rmvClient(Client *client) 
{
    _clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
	client->setChannel(nullptr); /* del current channel from client object */
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
    rmvClient(client); /* remove client from channel first */
    //* REPLY() send message to channel -> client kicked + comment about it
    _server->log(CLIENTKICKED(client->getNickname()) + comment);
}

void    Channel::broadcast(std::string const &message)
{
    vector<Client*>::iterator   cit = _clients.begin();
    for (; cit != _clients.end(); cit++)
		(*cit)->write(message);
    _server->log(MSGBROADCASTEDTOCHANNEL(message));
}